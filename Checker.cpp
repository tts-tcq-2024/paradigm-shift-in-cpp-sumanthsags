#include <assert.h>
#include <iostream>
using namespace std;

int isOutOfRange(float value, float lowerBound, float upperBound)
{
  return (value < lowerBound || value > upperBound);
}

bool batteryIsOk(float temperature, float soc, float chargeRate)
{
  int count = 0;
  count = isOutOfRange(temperature, 0, 45);
  count = isOutOfRange(soc, 20, 80);

  if (count > 1)
  {
    cout << "Battery not okay\n";
    return false;
  }
  else
  {
    return true;
  }
}

int main()
{
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
