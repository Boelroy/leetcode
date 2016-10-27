#include "limits.h"

int divide(int dividend, int divisor) {
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;

    int flag = dividend < 0 ^ divisor < 0;

    unsigned int A = dividend > 0 ? dividend : -dividend;
    unsigned int B = divisor > 0 ? divisor : -divisor;

    unsigned int result = 0;

    while(B <= A) {
        unsigned int count = 1, tmp = B;

        while (A >= tmp << 1 && tmp < INT_MAX ){
            tmp = tmp << 1;
            count = count << 1;
        }
        result+=count;

        A-=tmp;
    }
    return flag ? -result : result;
}
