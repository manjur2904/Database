#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <chrono>

// Assuming your ThreadPool class is implemented correctly
// and is included in "ThreadPool.h"
#include "ThreadPool.h"

void exampleTask(ThreadPool &pool)
{
    Logger *logger = pool.getLoggerForThread();

    if (logger)
    {
        std::stringstream ss;
        ss << "exampleTask Task started by thread " << std::this_thread::get_id();
        logger->log(ss.str());
    }

    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work

    if (logger)
    {
        std::stringstream ss;
        ss << "exampleTask Task completed by thread " << std::this_thread::get_id();
        logger->log(ss.str());
    }
}

int main()
{
    ThreadPool pool(4);

    std::vector<std::future<void>> results;

    for (int i = 0; i < 40; ++i)
    {
        results.emplace_back(pool.enqueue(exampleTask, std::ref(pool)));
    }

    for (auto &result : results)
    {
        result.get();
    }

    std::cout << "All tasks completed" << std::endl;

    return 0;
}
