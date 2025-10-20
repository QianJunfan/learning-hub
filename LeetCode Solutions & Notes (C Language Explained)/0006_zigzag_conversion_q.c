// Mon Oct 20, 2025
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// solution 1 - brute force (so stupid...)
char *convert_bf(char *s, int n)
{
	// init
	int len = strlen(s);
	// bdry
	if (len <= 1 || len == 0) {
		char *result = (char **)malloc(len + 1);
		strcpy(result, s);
		return result;
	}
		
	int h = n;
	int w = (len / (n - 1)) * (n - 1) + n;
	char str[h][w];
	for(int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			str[i][j] = ' ';
	
	// prog
	bool run = true;
	bool dirct_down = true;
		// if = true  : stright down
		// if = false : turn right up;
	int cur_h = 0;
	int cur_w = 0;
	int cur = 0;
	while (run) {
		str[cur_h][cur_w] = s[cur];
        	cur ++;

        	if (cur >= len) {
           		run = false;
            	 	break;
        	}

    	     	if (cur_h == h - 1)
         		dirct_down = false;
        	else if (cur_h == 0)
            		dirct_down = true;
        	

        	if (dirct_down) {
            		cur_h ++;
		} else {
            		cur_h --;
            		cur_w ++;
		}
	}
	char *result = (char *)malloc(len + 1);
	int idx = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (str[i][j] != ' ')
				result[idx++] = str[i][j];
	result[idx] = '\0';
	return result;	
				
}

char *convert(char *s, int n)
{
	// init
	int len = strlen(s);
	// bdry
	if (len <= 1 || len == 0) {
		char *result = (char *)malloc(len + 1);
		strcpy(result, s);
		return result;
	}

	char **t = (char *)malloc(n * sizeof(char *));
	int *row_len = (int *)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		t[i] = (char **)malloc(len + 1);
	
	int cur_row = 0;
	int direction = 1;
	for (int i = 0; i < len; i++) {
		t[cur_row][row_len[cur_row]] = s[i];

		row_len[cur_row] ++;
		if (cur_row == 0)
			direction = 1;
		else if (cur_row == n - 1)
			direction = -1;

		cur_row += direction;
	}

	char *result = (char *)malloc(len + 1);

	int idx = 0;
	for (int i = 0; i < n; i++) {
		memcpy(result + idx, t[i], row_len[i]);
		idx += row_len[i];
		free(t[i]);
	}
	result[idx] = '\0';

	free(t);
	free(row_len);

	return result;
}

int main(void)
{
	char *s = "PAYPALISHIRING";
	char *a = "ABC";
	convert(a, 1);
	return 0;
}
