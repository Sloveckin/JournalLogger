#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H

#include "logger/data/Importance.hpp"
#include "logger/data/Note.hpp"

#include <fstream>
#include <string>

namespace logger {

class Logger {
public:
  using FilePath = std::string;

  Logger() = delete;

  Logger(const FilePath& file_path, const data::Importance importace = data::Importance::MEDIUM);

  Logger(const Logger& other) = delete;
  Logger(Logger&& other) = delete;

  Logger& operator=(const Logger& other) = delete;
  Logger& operator=(Logger&& other) = delete;

  void log(const data::Note& note) const;

  void set_importance(const data::Importance importance) noexcept;

  ~Logger() noexcept;

private:
  data::Importance importance_;
  mutable std::ofstream file_;
};

} // namespace logger

#endif
