#ifndef LOGGER_EXCEPTION_LOGGER_FILE_NOT_FOUND_H
#define LOGGER_EXCEPTION_LOGGER_FILE_NOT_FOUND_H

#include "logger/exception/logger/LoggerException.hpp"

#include <string>

namespace logger {

namespace exception {

namespace logger {

class LoggerFileNotFound : public LoggerException {
public:
  LoggerFileNotFound() = delete;

  LoggerFileNotFound(const std::string& path);

  LoggerFileNotFound(const LoggerFileNotFound& other) = default;
  LoggerFileNotFound(LoggerFileNotFound&& other) = default;

  LoggerFileNotFound& operator=(const LoggerFileNotFound& other) = default;
  LoggerFileNotFound& operator=(LoggerFileNotFound&& other) = default;

  ~LoggerFileNotFound() noexcept = default;
};

} // namespace logger

} // namespace exception

} // namespace logger

#endif
