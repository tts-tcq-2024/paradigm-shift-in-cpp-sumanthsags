#include "Battery.hpp"
#include <string>
#include <iostream>

Battery::Battery(float temp, float stateOfCharge, float charge, std::vector<ParameterCheck*> checkArray)
    : temperature(temp), soc(stateOfCharge), chargeRate(charge), checks(checkArray) {}

bool checkBatteryParameter(BatteryCheck* check, double value, std::vector<std::string>& messages, int& warnings, int& breaches)
{
    BatteryStatus status = check->check(value);
    if (status != NORMAL) 
    {
        messages.push_back(check->message(status));
        if (status == LOW_TEMP_BREACH || status == HIGH_TEMP_BREACH || status == LOW_SOC_BREACH || status == HIGH_SOC_BREACH || status == CHARGE_RATE_BREACH) 
        {
            breaches++;
        } 
        else 
        {
            warnings++;
        }
    }
    return (status == NORMAL);
}

bool Battery::isBatteryOk(std::vector<std::string>& messages) 
{
    int warnings = 0;
    int breaches = 0;

    // Check temperature
    bool tempOk = checkBatteryParameter(checks[0], temperature, messages, warnings, breaches);

    // Check SOC
    bool socOk = checkBatteryParameter(checks[1], soc, messages, warnings, breaches);

    // Check charge rate
    bool chargeRateOk = checkBatteryParameter(checks[2], chargeRate, messages, warnings, breaches);

    return (breaches == 0);
}
