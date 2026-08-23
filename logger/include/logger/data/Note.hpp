#ifndef LOGGER_DATA_NOTE_H
#define LOGGER_DATA_NOTE_H

#include <ctime>
#include <string>
#include <chrono>

#include "Importance.hpp"


namespace logger {
    namespace data {

        class Note {
        public:

            using Message = std::string;
            using Time = std::chrono::time_point<std::chrono::system_clock>;
            //using Time = time_t;

            Note() = delete;
            
            Note(const Message& message, const Importance importance, const Time& time);

            Note(const Note& other) = default;
            Note(Note&& other) = default;

            Note& operator=(const Note& other) = default;
            Note& operator=(Note&& other) = default;

            Message& message() noexcept;
            const Message& message() const noexcept;

            Importance importance() const noexcept;

            Time& time() noexcept;
            const Time& time() const noexcept;
            
            ~Note() noexcept = default;
        private:
            Message message_;
            Importance importance_;
            Time time_;
        };

    }
}

#endif