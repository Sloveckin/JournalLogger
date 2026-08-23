#include "logger/Logger.hpp"

#include "logger/data/Importance.hpp"
#include "logger/exception/logger/LoggerFileNotFound.hpp"
#include "logger/exception/logger/LoggerWriteException.hpp"
#include <chrono>
#include <ios>


namespace logger {

    Logger::Logger(const Logger::FilePath& path, const data::Importance importance) : file_(path, std::ios::app), importance_(importance) {
        if (!this->file_.is_open()) {
            throw exception::logger::LoggerFileNotFound(path);
        }
        this->file_.exceptions(std::ofstream::badbit);
    }

    void Logger::log(const data::Note& note) const {
        if (note.importance() < this->importance_) {
            return;
        }

        try {

            const std::time_t current_time = std::chrono::system_clock::to_time_t(note.time());
            const std::string importance_str = data::importance_to_string(note.importance());

            this->file_ << "Importance: " <<  importance_str << '\n';
            this->file_ << "Message: " << note.message() << '\n';
            this->file_ << "Time: " << ctime(&current_time) << '\n';
        } catch (const std::ios_base::failure& e) {
            throw exception::logger::LoggerWriteException(e.what());
        }

    }

    void Logger::set_importance(const data::Importance importance) noexcept {
        this->importance_ = importance;
    }

    Logger::~Logger() noexcept {
        this->file_.close();
    }

}