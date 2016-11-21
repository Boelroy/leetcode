#include "math.h"

double myPow(double x, int n) {
  if (n == 0) return 1;
  if (x == 0 && n < 0) return INFINITY;
  if (x == 0) return 0;

  double result = 1;
  if (n < 0) {
    x = result / x;
    n = -n;
  }

  while(n > 0) {
    if ( n % 2) {
      result *= x;
    }
    x = x * x;
    n = n / 2;
  }

  return result;
}
