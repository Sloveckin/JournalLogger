#include "logger/Logger.hpp"
#include "logger/data/Importance.hpp"
#include "logger/data/Note.hpp"
#include "logger/exception/logger/LoggerException.hpp"
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <mutex>
#include <queue>

static logger::data::Importance convert_str_to_importance(const std::string& str) {
    if (str == "low") {
        return logger::data::Importance::LOW;
    } else if (str == "medium") {
        return logger::data::Importance::MEDIUM;
    } else if (str == "high") {
        return logger::data::Importance::HIGH;
    }

    throw std::invalid_argument("incorrent importance");
}

static void write(const logger::Logger& logger, std::queue<logger::data::Note>& queue,  std::mutex& mtx, std::condition_variable& condition, bool& stop) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
    
        condition.wait(lock, [&] {
            return !queue.empty() || stop;
        });

        if (stop && queue.empty()) {
            return;
        }
        
        try {
            logger.log(queue.front());
            queue.pop();
        } catch (const logger::exception::logger::LoggerException& e) {
            stop = true;
            std::cout << "Error: " << e.what() << '\n';
            std::cout << "Stop doing..\n";
        }
    }
}

static logger::data::Importance read_importance(const std::string& importance_str) {

    try {
        return convert_str_to_importance(importance_str);
    } catch (const std::invalid_argument& e1) {
        while (true) {
            try {
                std::string input;
                std::cin >> input;
                return convert_str_to_importance(importance_str);
            } catch (const std::invalid_argument& e2) {
                std::cout << "Invalid importance value\nRepeat again\n";
            }
        }
    }
}

static void read(std::queue<logger::data::Note>& queue, std::mutex& mtx, std::condition_variable& condition, bool& stop, const logger::data::Importance deafult_importance) {
    while (true) {
        std::string input;
        std::cout << "Write message\n";
        if (!std::getline(std::cin, input)) {
            {
                std::unique_lock<std::mutex> lock(mtx);
                stop = true;
            }
            condition.notify_one();
            return;
        }

        std::cout << "Write importance\n";
        std::string importance_str;
        if (!std::getline(std::cin, importance_str)) {
            {
                std::unique_lock<std::mutex> lock(mtx);
                stop = true;
            }
            condition.notify_one();
            return;
        }

        logger::data::Importance importance;
        if (importance_str.empty()) {
            importance = deafult_importance;
        } else {
            importance = read_importance(importance_str);
        }

        const auto time = std::chrono::system_clock::now();

        logger::data::Note note(input, importance, time);

        {
            std::unique_lock<std::mutex> lock(mtx);
            queue.push(note);
        }

        condition.notify_one();
    }
}

int main(int argc, char** argv) {

    if (argc != 3) {
        std::cout << "Invalid input. Expected <path-to-log-file> <default-importance>\n"; 
        return -1;        
    }

    try {
        const std::string path_to_file = argv[1];
        const logger::data::Importance default_importance = convert_str_to_importance(argv[2]);

        const logger::Logger logger(path_to_file, default_importance);

        std::condition_variable condition;
        std::mutex mtx;
        bool stop = false;

        std::queue<logger::data::Note> queue;

        std::thread worker(write, std::ref(logger), std::ref(queue), std::ref(mtx), std::ref(condition), std::ref(stop));
        std::thread reader(read, std::ref(queue), std::ref(mtx), std::ref(condition), std::ref(stop), default_importance);

        worker.join();
        reader.join();

    } catch (const logger::exception::logger::LoggerException& e) {
        std::cout << e.what() << '\n';
        return -1;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << '\n';
        return -1;
    }

    return 0;
}