#include "SocCheck.hpp"

SocCheck::SocCheck() 
{
    ranges.push_back({0, 20, LOW_SOC_BREACH});
    ranges.push_back({21, 24, LOW_SOC_WARNING});
    ranges.push_back({24, 75, NORMAL});
    ranges.push_back({76, 80, HIGH_SOC_WARNING});
    ranges.push_back({81, 100, HIGH_SOC_BREACH});

    statusMessages = 
    {
        { LOW_SOC_BREACH, "State of Charge is too low!" },
        { LOW_SOC_WARNING, "State of Charge is low!" },
        { HIGH_SOC_WARNING, "State of Charge is high!" },
        { HIGH_SOC_BREACH, "State of Charge is too high!" },
    };
}

BatteryStatus SocCheck::check(float value) 
{
    for (const auto& range : ranges) 
    {
        if (value >= range.lower && value <= range.upper) 
        {
            return range.status;
        }
    }
    return NORMAL;
}

std::string SocCheck::message(BatteryStatus status) 
{
    auto it = statusMessages.find(status);
    if (it != statusMessages.end()) 
    {
        return it->second;
    }
    return "Unknown status";
}
