// Mon Oct 20, 2025
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// solution 1
char str_test[] = "abcd";

char *convert(char *s, int numRows)
{
        int len = strlen(s);
        int loop_len = 2 * numRows - 2;
        int loc = 0;
        int run = 0;
        char new_str[len + 1];
        if (numRows == 1) return s;
        
        for(int i = 0; i < len; i++) {

                if (loc + run * loop_len >= len) {
                        loc ++;
                        run = 0;
                }
                if (loc != 0 && loc != numRows-1) {
                        new_str[i] = s[loc +  run*loop_len];
                        if (loop_len - loc + run*loop_len < len) {
                                new_str[i+1] = s[loop_len - loc + run*loop_len];
                                i++;
                        }
                }
                if (loc == 0 || loc == numRows - 1) {
                        new_str[i] = s[loc + run*loop_len];
                }
                run ++;
        }
        new_str[len] = '\0';
        char *result = (char*)malloc(len+1);
        printf("%s\n", new_str);
        strcpy(result, new_str);
        return result;
}

int main(void)
{
        printf("TEST STR IS: %s\n NEW STR IS: %s\n", str_test,  convert(str_test, 3));
        return 0;
}
