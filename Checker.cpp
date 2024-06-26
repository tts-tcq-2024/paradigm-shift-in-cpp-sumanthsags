#include <assert.h>
#include <iostream>
using namespace std;

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool isTemperatureInRange = (temperature >= 0 && temperature <= 45);
  bool isSocInRange = (soc >= 20 && soc <= 80);
  bool isChargeRateInRange = (chargeRate <= 0.8);

  if (!isTemperatureInRange) {
    cout << "Temperature out of range!\n";
    return false;
  }

  if (!isSocInRange) {
    cout << "State of Charge out of range!\n";
    return false;
  }

  if (!isChargeRateInRange) {
    cout << "Charge Rate out of range!\n";
    return false;
  }

  return true;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
