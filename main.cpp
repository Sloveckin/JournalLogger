#include <chrono>
#include <iostream>

#include "logger/Logger.hpp"
#include "logger/data/Importance.hpp"

int main() {
    std::cout << "Journal writer\n";

    logger::Logger logger("./log.txt");
    
    logger::data::Note note("message", logger::data::Importance::HIGH, std::chrono::system_clock::now());

    logger.write(note);

    return 0;
}