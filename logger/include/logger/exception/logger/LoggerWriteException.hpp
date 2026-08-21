#ifndef LOGGER_EXCEPTION_LOGGER_WRITE_EXCEPTION_H
#define LOGGER_EXCEPTION_LOGGER_WRITE_EXCEPTION_H

#include "logger/exception/logger/LoggerException.hpp"
#include <string>

namespace logger {
    namespace exception {
        namespace logger {
            class LoggerWriteException : public LoggerException {
            public:
                LoggerWriteException() = delete;

                LoggerWriteException(const std::string& message);
                
                LoggerWriteException(const LoggerWriteException& other) = default;
                LoggerWriteException(LoggerWriteException&& other) = default;

                LoggerWriteException& operator=(const LoggerWriteException& other) = default;
                LoggerWriteException& operator=(LoggerWriteException&& other) = default;

                ~LoggerWriteException() noexcept = default;
            };

        }
    }
}

#endif