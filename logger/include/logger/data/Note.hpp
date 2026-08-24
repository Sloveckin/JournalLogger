#ifndef LOGGER_DATA_NOTE_H
#define LOGGER_DATA_NOTE_H

#include "Importance.hpp"

#include <chrono>
#include <ctime>
#include <string>

namespace logger {
namespace data {
/**
 * @brief Class for note
 * 
 * Class for representing note
 */
class Note {
public:
  /** Text with message */
  using Message = std::string;
  /** Time when note was created */
  using Time = std::chrono::time_point<std::chrono::system_clock>;

  Note() = delete;

  /**
   * @brief Construct a new Note object
   * 
   * @param message text with message
   * @param importance importance of note
   * @param time when note was created
   */
  Note(const Message& message, const Importance importance, const Time& time);

  /**
   * @brief Construct a new Note object
   * 
   * @param other Note
   */
  Note(const Note& other) = default;

  /**
   * @brief Construct a new Note object
   * 
   * @param other Note that will be moved
   */
  Note(Note&& other) = default;

  /**
   * @brief Operator = for Note
   * 
   * @param other Note
   * @return Note&
   */
  Note& operator=(const Note& other) = default;
  /**
   * @brief Operator = for Note with movement
   * 
   * @param other Note that will be moved
   * @return Note& 
   */
  Note& operator=(Note&& other) = default;

  /**
   * @brief Get message
   * 
   * @return Message& 
   */
  Message& message() noexcept;

  /**
   * @brief Get const reference to message
   * 
   * @return const Message& 
   */
  const Message& message() const noexcept;

  /**
   * @brief Get importance
   * 
   * @return Importance 
   */
  Importance importance() const noexcept;

  /**
   * @brief Get time
   * 
   * @return Time& 
   */
  Time& time() noexcept;

  /**
   * @brief Get const reference to time
   * 
   * @return const Time& 
   */
  const Time& time() const noexcept;

  /**
   * @brief Default desctuctor that not throw exceptions
   * 
   */
  ~Note() noexcept = default;

private:
  /** Message with text */
  Message message_; 
  /** Importance */
  Importance importance_;
  /** Time when note was created */
  Time time_;
};

} // namespace data
} // namespace logger

#endif
