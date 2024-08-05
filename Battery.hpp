#ifndef BATTERY_HPP
#define BATTERY_HPP

#include <vector>
#include "ParameterCheck.hpp"
#include "TemperatureCheck.hpp"
#include "SocCheck.hpp"
#include "ChargeRateCheck.hpp"
#include "BatteryCheck.hpp"
#include <string>

class Battery {
    float temperature;
    float soc;
    float chargeRate;
    std::vector<ParameterCheck*> checks;
public:
    Battery(float temp, float stateOfCharge, float charge, std::vector<ParameterCheck*> checkArray);
    bool checkBatteryParameter(std::vector<ParameterCheck*> check,double value, std::vector<std::string>& messages, int& warnings, int& breaches);
    bool isBatteryOk(std::vector<std::string>& messages);
};

#endif // BATTERY_HPP
