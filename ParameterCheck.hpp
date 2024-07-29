#ifndef PARAMETER_CHECK_HPP
#define PARAMETER_CHECK_HPP

#include "BatteryCheck.hpp"
#include <string>

class ParameterCheck {
public:
    virtual BatteryStatus check(float value) = 0;
    virtual std::string message(BatteryStatus status) = 0;
    virtual ~ParameterCheck() = default;
};

#endif // PARAMETER_CHECK_HPP
