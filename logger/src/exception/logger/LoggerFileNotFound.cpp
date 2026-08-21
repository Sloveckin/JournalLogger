#include "logger/exception/logger/LoggerFileNotFound.hpp"
#include "logger/exception/logger/LoggerException.hpp"

namespace logger {
    namespace exception {
        namespace logger {
            LoggerFileNotFound::LoggerFileNotFound(const std::string& path) : LoggerException("File not found: " + path) {

            }
        }
    }
}