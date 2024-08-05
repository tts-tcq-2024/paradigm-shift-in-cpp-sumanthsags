#include "SocCheck.hpp"

SocCheck::SocCheck() 
{
    socThresholds[20] = LOW_SOC_BREACH;
    socThresholds[24] = LOW_SOC_WARNING;
    socThresholds[75] = NORMAL;
    socThresholds[80] = HIGH_SOC_WARNING;
    socThresholds[100] = HIGH_SOC_BREACH;

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
    for (const auto& threshold : socThresholds) 
    {
        if (value <= threshold.first) 
        {
            return threshold.second;
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
