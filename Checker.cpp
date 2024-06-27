#include <assert.h>
#include <iostream>
using namespace std;

bool batteryIsOk(float temperature, float soc, float chargeRate)
{
  bool isBatteryOk = (temperature >= 0 && temperature <= 45);
  isBatteryOk = (soc >= 20 && soc <= 80);
  isBatteryOk = (chargeRate <= 0.8);

  if (!isBatteryOk)
  {
    cout << "Battery not okay\n";
    return false;
  }
  return true;
}

int main()
{
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
