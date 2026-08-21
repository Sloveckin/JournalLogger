#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H

#include <fstream>
#include <string>

#include "logger/data/Note.hpp"
#include "logger/data/Importance.hpp"

namespace logger {
    class Logger {
    public:

        using FilePath = std::string;

        Logger() = delete;

        Logger(const FilePath& file_path, const data::Importance importace = data::Importance::MEDIUM);

        Logger(const Logger& other) = delete;
        Logger(Logger&& other) = delete;

        Logger& operator=(const Logger& other) = delete;
        Logger& operator=(Logger&& other) =  delete;

        void write(const data::Note& note) const;

        ~Logger() noexcept;

    private:
        data::Importance importance_;
        mutable std::ofstream file_;
    };
}


#endif