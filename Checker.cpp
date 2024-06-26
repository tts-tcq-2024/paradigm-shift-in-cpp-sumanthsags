#include <assert.h>
#include <iostream>
using namespace std;

bool isOutOfRange(float value, float lowerBound, float upperBound)
{
  return (value < lowerBound || value > upperBound);
}

bool batteryIsOk(float temperature) 
{
  if (isOutOfRange(temperature, 0, 45)) 
  {
    cout << "Battery parameters out of range!\n";
    return false;
  }
  return true;
}

int main()
{
  assert(batteryIsOk(25) == true);
  assert(batteryIsOk(50) == false);
}
