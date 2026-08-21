#include "logger/exception/logger/LoggerException.hpp"

namespace logger {
    namespace exception {
        namespace logger {
            LoggerException::LoggerException(const std::string& message) : message_(message) {

            }

            const char* LoggerException::what() const noexcept {
                return this->message_.c_str();
            }
        }
    }
}