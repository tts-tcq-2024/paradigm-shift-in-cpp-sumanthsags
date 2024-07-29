#include "ChargeRateCheck.hpp"

ChargeRateCheck::ChargeRateCheck() : threshold(0.8) {}

BatteryStatus ChargeRateCheck::check(float value) {
    if (value > threshold) {
        return CHARGE_RATE_BREACH;
    }
    return NORMAL;
}

std::string ChargeRateCheck::message(BatteryStatus status) {
    if (status == CHARGE_RATE_BREACH) {
        return "Charge rate is too high!";
    }
    return "";
}
