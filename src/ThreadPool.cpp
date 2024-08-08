#include "ThreadPool.h"
#include <sstream>

// const std::string LOG_DIR = "log/";

ThreadPool::ThreadPool(size_t numThreads) : stop(false)
{
    for (size_t i = 0; i < numThreads; ++i)
    {
        std::string logFileName = LOG_DIR + "thread_" + std::to_string(i) + ".log";
        workers.emplace_back([this, logFileName]()
                             {
                                 std::thread::id threadId = std::this_thread::get_id();
                                 {
                                     std::lock_guard<std::mutex> lock(loggerMutex);
                                     loggers[threadId] = std::make_unique<Logger>(logFileName);
                                 }
                                 workerThread();
                                 {
                                     std::lock_guard<std::mutex> lock(loggerMutex);
                                     loggers.erase(threadId);
                                 } });
    }
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        stop = true;
    }
    condition.notify_all();
    for (std::thread &worker : workers)
    {
        if (worker.joinable())
        {
            worker.join();
        }
    }
}

void ThreadPool::workerThread()
{
    std::thread::id threadId = std::this_thread::get_id();
    Logger *threadLogger = getLoggerForThread();

    while (true)
    {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this]
                           { return stop || !tasks.empty(); });
            if (stop && tasks.empty())
            {
                return;
            }
            task = std::move(tasks.front());
            tasks.pop();
        }

        std::stringstream ss;
        ss << threadId; // Convert threadId to string using stringstream

        if (threadLogger)
        {
            threadLogger->log("Task started by thread " + ss.str());
        }
        task();
        if (threadLogger)
        {
            threadLogger->log("Task completed by thread " + ss.str());
        }
    }
}

Logger *ThreadPool::getLoggerForThread()
{
    std::thread::id threadId = std::this_thread::get_id();
    std::lock_guard<std::mutex> lock(loggerMutex);
    auto it = loggers.find(threadId);
    return (it != loggers.end()) ? it->second.get() : nullptr;
}

// template <class F, class... Args>
// auto ThreadPool::enqueue(F &&f, Args &&...args) -> std::future<typename std::result_of<F(Args...)>::type>
// {
//     using returnType = typename std::result_of<F(Args...)>::type;

//     auto task = std::make_shared<std::packaged_task<returnType()>>(
//         std::bind(std::forward<F>(f), std::forward<Args>(args)...));
//     std::future<returnType> res = task->get_future();
//     {
//         std::unique_lock<std::mutex> lock(queueMutex);
//         if (stop)
//         {
//             throw std::runtime_error("enqueue on stopped ThreadPool");
//         }
//         tasks.emplace([task]() { (*task)(); });
//     }
//     condition.notify_one();
//     return res;
// }
