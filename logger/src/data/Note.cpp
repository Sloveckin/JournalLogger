#include "logger/data/Note.hpp"
#include "logger/data/Importance.hpp"

namespace logger {
    namespace data {
        Note::Note(const Note::Message& message, const Importance importance, const Note::Time& time) : message_(message), importance_(importance), time_(time) {

        }

        Note::Message& Note::message() noexcept {
            return this->message_;
        }

        const Note::Message& Note::message() const noexcept {
            return this->message_;
        }

        Importance Note::importance() const noexcept {
            return this->importance_;
        }

        Note::Time& Note::time() noexcept {
            return this->time_;
        }

        const Note::Time& Note::time() const noexcept {
            return this->time_;
        }
    } 
}