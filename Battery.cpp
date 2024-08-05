#include "Battery.hpp"
#include <string>
#include <iostream>

Battery::Battery(float temp, float stateOfCharge, float charge, std::vector<ParameterCheck*> checkArray)
    : temperature(temp), soc(stateOfCharge), chargeRate(charge), checks(checkArray) {}

bool Battery::isBatteryOk(std::vector<std::string>& messages) 
{
    int warnings = 0;
    int breaches = 0;
 
    // Check temperature
    BatteryStatus tempStatus = checks[0]->check(temperature);
    if (tempStatus != NORMAL) 
    {
        messages.push_back(checks[0]->message(tempStatus));
        if (tempStatus == LOW_TEMP_BREACH || tempStatus == HIGH_TEMP_BREACH) {
            breaches++;
        } else {
            warnings++;
        }
    }
 
    // Check SOC
    BatteryStatus socStatus = checks[1]->check(soc);
    if (socStatus != NORMAL) {
        messages.push_back(checks[1]->message(socStatus));
        if (socStatus == LOW_SOC_BREACH || socStatus == HIGH_SOC_BREACH) {
            breaches++;
        } else {
            warnings++;
        }
    }
 
    // Check charge rate
    BatteryStatus chargeRateStatus = checks[2]->check(chargeRate);
    if (chargeRateStatus != NORMAL) {
        messages.push_back(checks[2]->message(chargeRateStatus));
        if (chargeRateStatus == CHARGE_RATE_BREACH) {
            breaches++;
        }
    }
 
    return (breaches == 0);
}
