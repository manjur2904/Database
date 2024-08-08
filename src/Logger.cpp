#include "Logger.h"
#include <iomanip>
#include <ctime>

Logger::Logger(const std::string &fileName)
{
    logFile.open(fileName, std::ios::out | std::ios::app);
    if (!logFile)
    {
        std::cerr << "Failed to open log file: " << fileName << std::endl;
    }
}

Logger::~Logger()
{
    if (logFile.is_open())
    {
        logFile.close();
    }
}

void Logger::log(const std::string &message)
{
    std::lock_guard<std::mutex> lock(logMutex);
    std::time_t now = std::time(nullptr);
    std::tm tm = *std::localtime(&now);
    logFile << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << " [INFO] " << message << std::endl;
}
