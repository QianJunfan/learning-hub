// Mon Oct 20, 2025

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
// solution 1 - brute force
int reverse(int x)
{
	long long reversed = 0;

	while (x != 0) {
		int pop = x % 10;
		x /= 10;

		if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && pop > 7))
            		return 0;

		if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && pop < -8))
            		return 0;

		reversed = reversed * 10 + pop;

	}

	return reversed;

}


int main(void)
{
	reverse(123456789);
	return 0;
}
