#include "TemperatureCheck.hpp"

TemperatureCheck::TemperatureCheck() {
    ranges.push_back({-100, 0, LOW_TEMP_BREACH});
    ranges.push_back({0, 45, NORMAL});
    ranges.push_back({45, 100, HIGH_TEMP_BREACH});
}

BatteryStatus TemperatureCheck::check(float value) {
    for (const auto& range : ranges) {
        if (value >= range.lower && value <= range.upper) {
            return range.status;
        }
    }
    return NORMAL;
}

std::string TemperatureCheck::message(BatteryStatus status) {
    switch (status) {
        case LOW_TEMP_BREACH: return "Temperature is too low!";
        case HIGH_TEMP_BREACH: return "Temperature is too high!";
        default: return "";
    }
}
