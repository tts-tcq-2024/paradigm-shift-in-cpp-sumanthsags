#include <assert.h>
#include <iostream>
using namespace std;

bool isOutOfRange(float value, float lowerBound, float upperBound)
{
  return (value < lowerBound || value > upperBound);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  if (isOutOfRange(temperature, 0, 45) || isOutOfRange(soc, 20, 80) || chargeRate > 0.8) 
  {
    cout << "Battery parameters out of range!\n";
    return false;
  }
  return true;
}

int main()
{
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
