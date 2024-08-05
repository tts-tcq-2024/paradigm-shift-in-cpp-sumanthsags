#ifndef TEMPERATURE_CHECK_HPP
#define TEMPERATURE_CHECK_HPP

#include "ParameterCheck.hpp"
#include <map>
#include <string>

class TemperatureCheck : public ParameterCheck 
{
    std::map<float, BatteryStatus> tempThresholds;
    std::map<BatteryStatus, std::string> statusMessages;
public:
    TemperatureCheck();
    BatteryStatus check(float value) override;
    std::string message(BatteryStatus status) override;
};

#endif // TEMPERATURE_CHECK_HPP
