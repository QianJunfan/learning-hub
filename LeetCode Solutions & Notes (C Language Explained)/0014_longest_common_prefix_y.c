// Tue Oct 21, 2025

#include <stdatomic.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char* longestCommonPrefix(char **strs, int strsize)
{
        // fetch shortest length
        if (strsize == 1)
                return strs[0];
        int len = strlen(strs[0]);
        for (int i = 1; i < strsize - 1; i++) {
                if (strlen(strs[i]) < len)
                        len = strlen(strs[i]);
        }

        char *result = (char*)malloc(sizeof(char) * 201);
        result[0] = '\0';
        int idx = 0;
        for (int n = 0; n < len; n++ ) {
                char temp = ' ';
                for(int s = 0; s < strsize - 1; s++){
                        if (strs[s][n] == strs[s+1][n])
                                temp = strs[s][n];
                        else return result;
                }
                result[idx] = temp;
                result[idx + 1] = '\0';
                idx ++;
        }
        return result;
}
