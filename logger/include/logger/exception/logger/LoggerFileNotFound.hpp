#ifndef LOGGER_EXCEPTION_LOGGER_FILE_NOT_FOUND_H
#define LOGGER_EXCEPTION_LOGGER_FILE_NOT_FOUND_H

#include "logger/exception/logger/LoggerException.hpp"

#include <string>

namespace logger {

namespace exception {

namespace logger {

/**
 * @brief Class for exception when file not found
 * 
 */
class LoggerFileNotFound : public LoggerException {
public:
  LoggerFileNotFound() = delete;

  /**
   * @brief Construct a new Logger File Not Found object 
   * 
   * @param path Path to file which wasn't found
   */
  LoggerFileNotFound(const std::string& path);
};

} // namespace logger

} // namespace exception

} // namespace logger

#endif
