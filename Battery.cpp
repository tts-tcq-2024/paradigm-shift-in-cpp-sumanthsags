#include "Battery.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

// Constructor remains unchanged
Battery::Battery(float temp, float stateOfCharge, float charge, std::vector<ParameterCheck*> checkArray)
    : temperature(temp), soc(stateOfCharge), chargeRate(charge), checks(checkArray) {}

// Define actions for each status
void processStatus(BatteryStatus status, int& warnings, int& breaches) 
{
    static const std::unordered_map<BatteryStatus, std::function<void()>> statusActions = {
        {LOW_TEMP_BREACH, [&]() { breaches++; }},
        {HIGH_TEMP_BREACH, [&]() { breaches++; }},
        {LOW_SOC_BREACH, [&]() { breaches++; }},
        {HIGH_SOC_BREACH, [&]() { breaches++; }},
        {CHARGE_RATE_BREACH, [&]() { breaches++; }}
    };

    // Default action for warnings
    if (statusActions.find(status) != statusActions.end()) 
    {
        statusActions.at(status)();
    } 
    else 
    {
        warnings++;
    }
}

void processParameterCheck(ParameterCheck* check, float value, std::vector<std::string>& messages, int& warnings, int& breaches) 
{
    BatteryStatus status = check->check(value);
    if (status != NORMAL) 
    {
        messages.push_back(check->message(status));
        processStatus(status, warnings, breaches);
    }
}

bool Battery::isBatteryOk(std::vector<std::string>& messages) 
{
    int warnings = 0;
    int breaches = 0;
 
    // Process each check
    processParameterCheck(checks[0], temperature, messages, warnings, breaches);  // Temperature check
    processParameterCheck(checks[1], soc, messages, warnings, breaches);         // SOC check
    processParameterCheck(checks[2], chargeRate, messages, warnings, breaches);  // Charge rate check

    return (breaches == 0);
}
