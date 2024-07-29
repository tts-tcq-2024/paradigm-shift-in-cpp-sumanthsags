#ifndef TEMPERATURE_CHECK_HPP
#define TEMPERATURE_CHECK_HPP

#include "ParameterCheck.hpp"
#include "Range.hpp"
#include <vector>

class TemperatureCheck : public ParameterCheck {
    std::vector<Range> ranges;
public:
    TemperatureCheck();
    BatteryStatus check(float value) override;
    std::string message(BatteryStatus status) override;
};

#endif // TEMPERATURE_CHECK_HPP
