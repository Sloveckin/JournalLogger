#ifndef LOGGER_EXCEPTION_LOGGER_LOGGER_EXCEPTION_H
#define LOGGER_EXCEPTION_LOGGER_LOGGER_EXCEPTION_H

#include <exception>
#include <string>

namespace logger {

namespace exception {

namespace logger {

class LoggerException : public std::exception {
public:
  LoggerException() = delete;

  LoggerException(const std::string& message);

  LoggerException(const LoggerException& other) = default;
  LoggerException(LoggerException&& other) = default;

  LoggerException& operator=(const LoggerException& other) = default;
  LoggerException& operator=(LoggerException&& other) = default;

  const char* what() const noexcept override;

  ~LoggerException() noexcept = default;

private:
  std::string message_;
};
} // namespace logger

} // namespace exception

} // namespace logger

#endif
