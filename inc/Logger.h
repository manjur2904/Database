#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <iostream>
#include <mutex>
#include <thread>

class Logger
{
public:
    explicit Logger(const std::string &fileName);
    ~Logger();

    // Log a message with thread ID
    void log(const std::string &message);

private:
    std::ofstream logFile;
    std::mutex logMutex;
};

#endif // LOGGER_H
