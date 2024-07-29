#include "SocCheck.hpp"

SocCheck::SocCheck() {
    ranges.push_back({0, 20, LOW_SOC_BREACH});
    ranges.push_back({21, 24, LOW_SOC_WARNING});
    ranges.push_back({24, 75, NORMAL});
    ranges.push_back({76, 80, HIGH_SOC_WARNING});
    ranges.push_back({81, 100, HIGH_SOC_BREACH});
}

BatteryStatus SocCheck::check(float value) {
    for (const auto& range : ranges) {
        if (value >= range.lower && value <= range.upper) {
            return range.status;
        }
    }
    return NORMAL;
}

std::string SocCheck::message(BatteryStatus status) {
    switch (status) {
        case LOW_SOC_BREACH: return "State of Charge is too low!";
        case LOW_SOC_WARNING: return "State of Charge is low!";
        case HIGH_SOC_WARNING: return "State of Charge is high!";
        case HIGH_SOC_BREACH: return "State of Charge is too high!";
        default: return "";
    }
}
