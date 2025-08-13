#include <stdio.h>

// Solution - Plain Approach - O(n)
int main() {
    // Init.
    int apples[10];
    int height;
    int count = 0;
    for (int i = 0; i <= 9; i++) {
        scanf("%d", &apples[i]);
    }
    scanf("%d", &height);
    height += 30;
    
    // Prog.
    for (int i = 0; i <= 9; i++) {
        if (height >= apples[i]) {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}