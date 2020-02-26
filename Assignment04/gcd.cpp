#include <iostream>
#include "usefulFunc.h"
#include<cmath>

using namespace std;
int calcGCD(int a, int b)
{
  a = abs(a);
  b = abs(b);
  int temp = a % b;
  while (temp > 0)
    {
      a = b;
      b = temp;
      temp = a % b;
    }
  return b;
}