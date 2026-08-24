#ifndef LOGGER_EXCEPTION_LOGGER_LOGGER_EXCEPTION_H
#define LOGGER_EXCEPTION_LOGGER_LOGGER_EXCEPTION_H

#include <exception>
#include <string>

namespace logger {

namespace exception {

namespace logger {
/**
 * @brief Basic class for logger exception
 * 
 */
class LoggerException : public std::exception {
public:
  LoggerException() = delete;

  /**
   * @brief Construct a new LoggerException with error message
   * 
   * @param message 
   */
  LoggerException(const std::string& message);

  /**
   * @brief Default method for exception
   * 
   * @return const char* 
   */
  const char* what() const noexcept override;

private:
  /// Exception message
  std::string message_;
};
} // namespace logger

} // namespace exception

} // namespace logger

#endif
