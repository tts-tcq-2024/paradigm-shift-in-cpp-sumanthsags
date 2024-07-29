#ifndef CHARGE_RATE_CHECK_HPP
#define CHARGE_RATE_CHECK_HPP

#include "ParameterCheck.hpp"

class ChargeRateCheck : public ParameterCheck {
    float threshold;
public:
    ChargeRateCheck();
    BatteryStatus check(float value) override;
    std::string message(BatteryStatus status) override;
};

#endif // CHARGE_RATE_CHECK_HPP
