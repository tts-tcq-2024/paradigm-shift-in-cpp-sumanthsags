#ifndef BATTERY_HPP
#define BATTERY_HPP

#include <vector>
#include "ParameterCheck.hpp"
#include "TemperatureCheck.hpp"
#include "SocCheck.hpp"
#include "ChargeRateCheck.hpp"
#include <string>

bool checkBatteryParameter(BatteryCheck* check, double value, std::vector<std::string>& messages, int& warnings, int& breaches);

class Battery {
    float temperature;
    float soc;
    float chargeRate;
    std::vector<ParameterCheck*> checks;
public:
    Battery(float temp, float stateOfCharge, float charge, std::vector<ParameterCheck*> checkArray);
    bool isBatteryOk(std::vector<std::string>& messages);
};

#endif // BATTERY_HPP
