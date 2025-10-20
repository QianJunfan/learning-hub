// Mon Oct 20, 2025
#include <stdio.h>

// brute force
bool isPalindrome_bf(int x) {
	// bdry
	if (x < 0)
		return false;
	if (x == 0)
		return true;

	// init
	int num = x;
	long long tmp = 0;

	// prog
	while (x != 0) {
		int pop = x % 10;
		x /= 10;
		
		tmp = tmp * 10 + pop; 
	}

	if (tmp == num)
		return true;
	else
		return false;
}


// best solution - half reversing
bool isPalindrome(int x)
{
	if (x < 0 || (x % 10 == 0 && x != 0))
		return false;

	int half = 0;

	while (x > half) {
		int pop = x % 10;
		half = half * 10 + pop;
		x /= 10;
	}

	return x == half || x == half / 10;
}

