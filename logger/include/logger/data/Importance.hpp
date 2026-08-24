#ifndef LOGGER_DATA_IMPORTANCE_H
#define LOGGER_DATA_IMPORTANCE_H

#include <string>

namespace logger {
namespace data {

/**
 * @brief Enum for importance 
 * 
 */
enum Importance {
  LOW = 0,
  MEDIUM = 1,
  HIGH = 2
};

/**
 * @brief Function that convert Importance to string
 * 
 * @param importance 
 * @return std::string 
 */
std::string importance_to_string(const Importance importance) noexcept;

} // namespace data

} // namespace logger

#endif
