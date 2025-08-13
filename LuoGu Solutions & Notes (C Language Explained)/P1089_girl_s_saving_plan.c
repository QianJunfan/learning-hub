#include <stdio.h>
// Solution - Plain Approach
int main() {
    // Init.
    int month     = 0;
    int current   = 0;
    int mother    = 0;
    int cost[12] = {0};
    
    for (int i = 0; i < 12; i++) {
        scanf("%d", &cost[i]);
    }
    
    // Prog.
    for (int i = 0; i < 12; i++) {
        month ++;
        current += 300;
        current -= cost[i];
        if (current >= 100) {
            mother  += current - (current % 100);
            current  = current % 100;
        }
        
        if (current < 0) {
            printf("%d\n", -month);
            return 0;
        }
    }
    
    printf("%d\n", current + (int)(mother / 10 * 12));
    
    return 0;
}