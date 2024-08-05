#include "TemperatureCheck.hpp"

TemperatureCheck::TemperatureCheck() 
{
    // Define thresholds and their corresponding statuses
    tempThresholds[-100] = LOW_TEMP_BREACH;
    tempThresholds[-95] = LOW_TEMP_WARNING;
    tempThresholds[45] = HIGH_TEMP_BREACH;
    tempThresholds[42.75] = HIGH_TEMP_WARNING;
    tempThresholds[0] = NORMAL;
    tempThresholds[100] = HIGH_TEMP_BREACH; // Adjusted to cover the upper range

    // Define status messages
    statusMessages = 
    {
        { LOW_TEMP_BREACH, "Temperature is too low!" },
        { LOW_TEMP_WARNING, "Temperature is approaching too low!" },
        { NORMAL, "Temperature is normal" },
        { HIGH_TEMP_WARNING, "Temperature is approaching too high!" },
        { HIGH_TEMP_BREACH, "Temperature is too high!" }
    };
}

BatteryStatus TemperatureCheck::check(float value) 
{
    // Iterate over the thresholds to find the corresponding status
    BatteryStatus lastStatus = NORMAL;
    for (const auto& threshold : tempThresholds) 
    {
        if (value <= threshold.first) 
        {
            return threshold.second;
        }
        lastStatus = threshold.second;
    }
    return lastStatus;
}

std::string TemperatureCheck::message(BatteryStatus status) 
{
    // Find and return the corresponding message
    auto it = statusMessages.find(status);
    if (it != statusMessages.end()) 
    {
        return it->second;
    }
    return "Unknown status";
}
