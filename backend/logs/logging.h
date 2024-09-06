// backend/utils/logging.h

#ifndef LOGGING_H
#define LOGGING_H

#include <string>

// Initialize the logger (open the log file)
void initLogger(const std::string& logFilePath);

// Write an informational message to the log
void logInfo(const std::string& message);

// Write an error message to the log
void logError(const std::string& message);

// Close the logger (close the log file)
void closeLogger();

#endif // LOGGING_H
