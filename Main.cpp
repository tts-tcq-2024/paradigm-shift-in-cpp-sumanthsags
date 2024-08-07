#include <iostream>
#include <vector>
#include <cassert>
#include "Battery.hpp"
#include "TemperatureCheck.hpp"
#include "SocCheck.hpp"
#include "ChargeRateCheck.hpp"

// Function to initialize the checks
std::vector<ParameterCheck*> initializeChecks() 
{
    std::vector<ParameterCheck*> checks;
    checks.push_back(new TemperatureCheck());
    checks.push_back(new SocCheck());
    checks.push_back(new ChargeRateCheck());
    return checks;
}

// Helper function to print results
void printBatteryResults(const std::string& label, bool batteryOk, const std::vector<std::string>& messages) 
{
    std::cout << "Checking " << label << ": " << (batteryOk ? "PASSED" : "FAILED") << std::endl;
    for (const std::string& message : messages) 
    {
        std::cout << message << std::endl;
    }
}

void testBatteries(const std::vector<ParameterCheck*>& checks) 
{
    Battery battery1(25, 70, 0.7, checks);
    Battery battery2(50, 85, 0, checks);

    std::vector<std::string> messages1;
    std::vector<std::string> messages2;

    bool battery1_ok = battery1.isBatteryOk(messages1);
    bool battery2_ok = battery2.isBatteryOk(messages2);

    printBatteryResults("battery1", battery1_ok, messages1);
    printBatteryResults("battery2", battery2_ok, messages2);

    assert(battery1_ok == true);
    assert(battery2_ok == false);
}

// Function to clean up the checks
void cleanupChecks(std::vector<ParameterCheck*>& checks) 
{
    for (auto check : checks) 
    {
        delete check;
    }
}

int main() 
{
    std::vector<ParameterCheck*> checks = initializeChecks();
    testBatteries(checks);
    cleanupChecks(checks);
    return 0;
}
