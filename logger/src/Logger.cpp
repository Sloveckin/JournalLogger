#include "logger/Logger.hpp"

#include "logger/data/Importance.hpp"
#include "logger/exception/logger/LoggerFileNotFound.hpp"
#include "logger/exception/logger/LoggerWriteException.hpp"
#include <ios>


namespace logger {

    Logger::Logger(const Logger::FilePath& path, const data::Importance importance) : file_(path), importance_(importance) {
        if (!this->file_.is_open()) {
            throw exception::logger::LoggerFileNotFound(path);
        }
        this->file_.exceptions(std::ofstream::badbit);
    }

    void Logger::write(const data::Note& note) const {
        if (note.importance() < this->importance_) {
            return;
        }

        try {
            this->file_ << "some string\n";
        } catch (const std::ios_base::failure& e) {
            throw exception::logger::LoggerWriteException(e.what());
        }

    }

    Logger::~Logger() noexcept {
        this->file_.close();
    }

}