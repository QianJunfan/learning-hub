// Tue Oct 21, 2025
// :__+)


// solution 1 - brute force
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
char reverse(char s)
{
	switch (s) {
		case '}': 
			return '{';
		case ']':
			return '[';
		case ')':
			return '(';
	}

	return 'a';
}


bool isValid(char* s) {
	// init
	char tmp[strlen(s)];
	if (strlen(s) == 1)
		return false;
	int cursor = 0;

	// prog
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			tmp[cursor] = s[i];
			cursor ++;
		} else {
			if (cursor == 0)
				return false;
			char n = reverse(s[i]);
			if (n == tmp[cursor - 1]) {
				cursor --;
			} else {

				return false;
			}
		}
	}
	if (cursor == 0)
		return true;
	else 
		return false;
}

// after
#include <stdlib.h>
bool _isValid(char *s)
{
	// bdry
	int len = strlen(s);
	if (len % 2 != 0)
		return false;
	
	// init
	char *stack = (char *)malloc(sizeof(char) * (len + 1));
	int cursor = 0;

	for (int i = 0; i < len; i++) {
		char cur = s[i];
		
		if (cur == '(' || cur == '{' || cur == '[') {
			stack[cursor] = cur;
			cursor ++;
		} else {
			if (cursor == 0) {
				free(stack);
				return false;
			}
			if (stack[cursor - 1] != reverse(s[i])) {
				free(stack);
				return false;
			}

			cursor --;
		}
	}
	free(stack);

	return (cursor == 0);
}


int main(void)
{
	char *s = "[";
	if (isValid(s))
		printf("true\n");
	else 
		printf("false\n");
	return 0;
}
