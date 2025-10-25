// Tue Oct 21, 2025
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// solution 1 - brute force
int to_int(char s)
{
	switch (s) {
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	}

	return 0;
}



// solution 2 - better look up
static const int MAP[256] = {
	['I'] = 1,
    	['V'] = 5,
    	['X'] = 10,
    	['L'] = 50,
    	['C'] = 100,
    	['D'] = 500,
    	['M'] = 1000
};

int romanToInt(char *s)
{
	int result = 0;
	int len = strlen(s);
	int next = 0;
	int cur = 0;
	for (int i = len - 1; i >= 0; i--) {
		cur = MAP[s[i]];
		
		if (cur < next)
			result -= cur;
		else
			result += cur;

		next = cur;

	}

	printf("%d\n", result);
	return result;
	
}

int main(void)
{
	char *s = "MCMXCIV";
	romanToInt(s);

	return 0;
}
