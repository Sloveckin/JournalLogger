#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H

#include "logger/data/Importance.hpp"
#include "logger/data/Note.hpp"

#include <fstream>
#include <string>

namespace logger {
/**
 * @brief Class that write notes into the file
 * 
 */
class Logger {
public:
  /** File path */
  using FilePath = std::string;

  /**
   * @brief Construct a new Logger object
   * 
   * @param file_path Path to file 
   * @param importace Default importance
   */
  Logger(const FilePath& file_path, const data::Importance importace = data::Importance::MEDIUM);

  Logger(const Logger& other) = delete;

  /**
   * @brief Construct a Logger by moving other Logger
   * 
   * @param other 
   */
  Logger(Logger&& other) = default;

  Logger& operator=(const Logger& other) = delete;
  /**
   * @brief Operator = with moving other Logger
   * 
   * @param other 
   * @return Logger& 
   */
  Logger& operator=(Logger&& other) = default;

  /**
   * @brief Write not into the file
   * 
   * If note importance less than default importance then note will not be written
   * @param note Note
   */
  void log(const data::Note& note) const;

  /**
   * @brief Set the importance object
   * 
   * @param importance New importance
   */
  void set_importance(const data::Importance importance) noexcept;

  ~Logger() noexcept;

private:
  /** Default importnce */
  data::Importance importance_;
  /** File */
  mutable std::ofstream file_;
};

} // namespace logger

#endif
