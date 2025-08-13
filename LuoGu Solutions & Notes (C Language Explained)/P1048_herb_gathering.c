#include <stdio.h>

int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

// Solution - Plain Solution
int main() {
    // Init.
    int capacity, item;
    scanf("%d %d", &capacity, &item);
    
    int weight[item],
    value [item];
    for (int i = 0; i < item; i++) {
        scanf("%d %d", &weight[i], &value[i]);
    }
    
    int dp[item + 1][capacity + 1];
    for (int i = 0; i < item + 1; i++) {
        for (int j = 0; j < capacity + 1; j++) {
            dp[i][j] = 0;
        }
    }
    
    // Prog.
    for (int cur_item = 1; cur_item <= item; cur_item++) {
        for (int cur_capacity = 1; cur_capacity <= capacity; cur_capacity++) {
            
            if (weight[cur_item - 1] > cur_capacity) {
                dp[cur_item][cur_capacity] = dp[cur_item - 1][cur_capacity];
            } else {
                int drop = dp[cur_item - 1][cur_capacity];
                int take = dp[cur_item - 1][cur_capacity - weight[cur_item - 1]] + value[cur_item - 1];
                
                dp[cur_item][cur_capacity] = max(drop, take);
            }
            
        }
    }
    
    printf("%d", dp[item][capacity]);
    return 0;
}