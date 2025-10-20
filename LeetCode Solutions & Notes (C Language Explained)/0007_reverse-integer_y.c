#include <stdio.h>
#include <math.h>
#include <limits.h>

int reverse(int x)
{
        long long reversed = 0;
        while (x != 0 ) {
                int dig = x % 10;
                x /= 10;
                if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && dig > 7))
                        return 0;
                if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && dig < -8))
                        return 0;
                reversed = reversed * 10 + dig;
        }        
        return reversed;
}

int main(void)
{
        printf("input: %d, output: %d",123,reverse(123));
        return 0;
}
