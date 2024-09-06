// backend/utils/logging.cpp

#include "logging.h"
#include <fstream>
#include <iostream>
#include <mutex>

static std::ofstream logFile;
static std::mutex logMutex;

void initLogger(const std::string& logFilePath) {
    std::lock_guard<std::mutex> lock(logMutex);
    logFile.open(logFilePath, std::ios::out | std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << logFilePath << std::endl;
    }
}

void logInfo(const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);
    if (logFile.is_open()) {
        logFile << "[INFO] " << message << std::endl;
    } else {
        std::cerr << "Log file is not open. Message: " << message << std::endl;
    }
}

void logError(const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);
    if (logFile.is_open()) {
        logFile << "[ERROR] " << message << std::endl;
    } else {
        std::cerr << "Log file is not open. Message: " << message << std::endl;
    }
}

void closeLogger() {
    std::lock_guard<std::mutex> lock(logMutex);
    if (logFile.is_open()) {
        logFile.close();
    }
}
