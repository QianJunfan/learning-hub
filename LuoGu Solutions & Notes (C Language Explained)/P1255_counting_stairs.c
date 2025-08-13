#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Solution 1 - Low Precision - Score: 40
//                            - TC: O(n), SC: O(n)
int climbStairs_low_p(int n){
    // Bdry.
    if (n <= 1) return 1;
    
    // Init.
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    
    // Prog.
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

// Solution 2 - High Precision - Score: 60
//                             - TC: O(n), SC: O(1)

long long climbStairs_high_p(long long n) {
    // Bdry.
    if (n <= 1) return 1;
    
    // Init.
    long long a = 1, b = 1, c;        // a = dp[i-2], b = dp[i-1], c = dp[i]
    
    // Prog.
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Solution 3 - Big Char - Score: 100
//                       - TC: O(n), SC: O(1)
void addStrings(char* a, char* b, char* res) {
    int len_a = (int)strlen(a);
    int len_b = (int)strlen(b);
    int max_len = (len_a > len_b) ? len_a : len_b;
    int carry = 0;
    int idx = 0;
    
    for (int i = 0; i < max_len || carry; i++) {
        int digit_a = (i < len_a) ? (a[len_a - 1 - i] - '0') : 0;
        int digit_b = (i < len_b) ? (b[len_b - 1 - i] - '0') : 0;
        int sum = digit_a + digit_b + carry;
        carry = sum / 10;
        res[idx++] = (sum % 10) + '0';
    }
    res[idx] = '\0';
    
    for (int i = 0; i < idx / 2; i++) {
        char tmp = res[i];
        res[i] = res[idx - 1 - i];
        res[idx - 1 - i] = tmp;
    }
}

char* climbStairs_char(int n) {
    // Bdry.
    if (n <= 1) {
        char* res = (char*)malloc(2 * sizeof(char));
        strcpy(res, "1");
        return res;
    }
    
    // Init.
    char* dp[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = (char*)malloc(10000 * sizeof(char));
    }
    
    strcpy(dp[0], "1");
    strcpy(dp[1], "1");
    
    
    // Prog.
    for (int i = 2; i <= n; i++) {
        addStrings(dp[i - 1], dp[i - 2], dp[i]);
    }
    
    char* result = (char*)malloc(strlen(dp[n]) + 1);
    strcpy(result, dp[n]);
    
    // Relm.
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    
    return result;
}


int main() {
    // Init.
    int n;
    scanf("%d", &n);
    
    // Prog.
    printf("%s\n", climbStairs_char(n));
    
    
    return 0;
}
