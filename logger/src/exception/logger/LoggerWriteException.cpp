#include "logger/exception/logger/LoggerWriteException.hpp"
namespace logger {
    namespace exception {
        namespace logger {
            LoggerWriteException::LoggerWriteException(const std::string& message) : LoggerException("Error while writing into the file: " + message) {

            }
        }
    }
}