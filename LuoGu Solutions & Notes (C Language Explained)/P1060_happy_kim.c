#include <stdio.h>

int max(int num1, int num2) {
    return (num1 >= num2) ? num1 : num2;
}

// Solution - Plain Approach
int main() {
    // Init.
    int money, wanted;
    scanf("%d %d", &money, &wanted);
    
    int price[wanted], rank[wanted];
    for (int i = 0; i < wanted; i++) {
        int tmp;
        scanf("%d %d", &price[i], &tmp);
        rank[i] = tmp * price[i];
    }
    
    int dp[wanted + 1][money + 1];
    for (int i = 0; i < wanted + 1; i++) {
        for (int j = 0; j < money + 1; j++) {
            dp[i][j] = 0;
        }
    }
    // Prog.
    for (int cur_wanted = 1; cur_wanted <= wanted; cur_wanted++) {
        for (int cur_money = 1; cur_money <= money; cur_money++) {
            if (cur_money < price[cur_wanted - 1]) {
                dp[cur_wanted][cur_money] = dp[cur_wanted - 1][cur_money];
            } else {
                int drop = dp[cur_wanted - 1][cur_money];
                int take = dp[cur_wanted - 1][cur_money - price[cur_wanted- 1]] + rank[cur_wanted - 1];
                
                dp[cur_wanted][cur_money] = max(take, drop);
            }
        }
    }
    
    printf("%d\n", dp[wanted][money]);
    
    return 0;
}