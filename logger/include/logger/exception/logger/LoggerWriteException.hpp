#ifndef LOGGER_EXCEPTION_LOGGER_WRITE_EXCEPTION_H
#define LOGGER_EXCEPTION_LOGGER_WRITE_EXCEPTION_H

#include "logger/exception/logger/LoggerException.hpp"

#include <string>

namespace logger {

namespace exception {

namespace logger {

/**
 * @brief Exception for situation when writing in file throw exceptoin
 * 
 */
class LoggerWriteException : public LoggerException {
public:
  /**
   * @brief Construct a new Logger Write Exception object with message
   * 
   * @param message Message
   */
  LoggerWriteException(const std::string& message);
};

} // namespace logger

} // namespace exception

} // namespace logger

#endif
