#include <stdio.h>

// Solution - Recursion - Out of time
int recursion(int number) {
    if (number == 1) return 1;
    int sum = 1;
    
    for (int i = 1; i <= number / 2; i++) {
        sum += recursion(i);
    }
    
    return sum;
}

// Solution - Dynamic Program - O(n^2)
int dp[1000 + 1] = {0};
int dynamic(int number) {
    // Init.
    int n;
    scanf("%d", &n);
    
    dp[1] = 1;
    
    // Prog.
    for (int i = 2; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= i / 2; j++) {
            dp[i] += dp[j];
        }
    }
    
    printf("%d\n", dp[n]);
    return 0;
}

