#ifndef SOC_CHECK_HPP
#define SOC_CHECK_HPP

#include "ParameterCheck.hpp"
#include "Range.hpp"
#include <vector>
#include <string>
#include <unordered_map>

class SocCheck : public ParameterCheck {
    std::vector<Range> ranges;
    std::unordered_map<BatteryStatus, std::string> statusMessages;
public:
    SocCheck();
    BatteryStatus check(float value) override;
    std::string message(BatteryStatus status) override;
};

#endif // SOC_CHECK_HPP
