// Tue Oct 21, 2025

#include <stdio.h>
#include <string.h>
/* wrong answer :(
enum rom{
        I = 1,
        V = 5,
        X = 10,
        L = 50,
        C = 100,
        D = 500,
        M = 1000,
        IV = 4,
        IX = 9,
        XL = 40,
        XC = 90,
        CD = 400,
        CM = 900,
};

int romanToInt(char *s)
{
        if (strcmp(s, "IV") == 0) return IV;
        if (strcmp(s, "IX") == 0) return IX;
        if (strcmp(s, "XL") == 0) return XL;
        if (strcmp(s, "XC") == 0) return XC;
        if (strcmp(s, "CD") == 0) return CD;
        if (strcmp(s, "CM") == 0) return CM;
        int val = 0;
        int i = 0;
        while (s[i] != '\0'){
                if (s[i] == 'I') val += I;
                if (s[i] == 'V') val += V;
                if (s[i] == 'X') val += X;
                if (s[i] == 'L') val += L;
                if (s[i] == 'C') val += C;
                if (s[i] == 'D') val += D;
                if (s[i] == 'M') val += M;
                i ++;
        }
        return val;
}
*/
// copy from q  -.<
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
        printf("%s = %d\n","III",romanToInt("III"));
        printf("%s = %d\n", "IX", romanToInt("IX"));
        printf("%s = %d\n", "CXII", romanToInt("CXII"));
        return 0;
}
