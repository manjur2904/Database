// // ThreadPool.tpp

// template <class F, class... Args>
// auto ThreadPool::enqueue(F &&f, Args &&...args) -> std::future<typename std::result_of<F(Args...)>::type>
// {
//     using returnType = typename std::result_of<F(Args...)>::type;
//     auto task = std::make_shared<std::packaged_task<returnType()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
//     std::future<returnType> res = task->get_future();
//     {
//         std::unique_lock<std::mutex> lock(queueMutex);
//         if (stop)
//             throw std::runtime_error("enqueue on stopped ThreadPool");
//         tasks.emplace([task]()
//                       { (*task)(); });
//     }
//     condition.notify_one();
//     return res;
// }