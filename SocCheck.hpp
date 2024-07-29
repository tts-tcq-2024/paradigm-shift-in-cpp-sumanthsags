#ifndef SOC_CHECK_HPP
#define SOC_CHECK_HPP

#include "ParameterCheck.hpp"
#include "Range.hpp"
#include <vector>

class SocCheck : public ParameterCheck {
    std::vector<Range> ranges;
public:
    SocCheck();
    BatteryStatus check(float value) override;
    std::string message(BatteryStatus status) override;
};

#endif // SOC_CHECK_HPP
