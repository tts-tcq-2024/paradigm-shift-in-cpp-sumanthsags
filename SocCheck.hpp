#ifndef SOC_CHECK_HPP
#define SOC_CHECK_HPP

#include "ParameterCheck.hpp"
#include "Range.hpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

class SocCheck : public ParameterCheck {
public:
    SocCheck();
    BatteryStatus check(float value) override;
    std::string message(BatteryStatus status) override;

private:
    std::map<float, BatteryStatus> socThresholds;
    std::unordered_map<BatteryStatus, std::string> statusMessages;
};

#endif // SOC_CHECK_HPP
