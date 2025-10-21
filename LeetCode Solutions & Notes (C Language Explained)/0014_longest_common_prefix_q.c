// Tue Oct 21, 2025
// :)

// solution 1 - brute force
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
	int length = 0;
	char *result = (char *)malloc(sizeof(char) * 200 + 1);
	strcpy(result, strs[0]);
	for (int i = 0; i < strsSize; i++) {
		int j = 0;

		while (result[j] != '\0' && strs[i][j] != '\0'
				&& result[j] == strs[i][j])
			j++;

		result[j] = '\0';

		if (result[0] == '0')
			break;
	}
	return result;
}


int main(void)

{
	char *strs[] = {"flower", "flow", "flight"};
	int size = 3;

	longestCommonPrefix(strs, size);
}
