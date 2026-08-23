#include "logger/data/Importance.hpp"

namespace logger {
    namespace data {
        std::string importance_to_string(const Importance importance) noexcept {
            switch (importance) {
            case LOW:
                return "low";
            case MEDIUM:
                return "medium";
            case HIGH:
                return "high";
            }
        }
    }
}