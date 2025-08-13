#include <stdio.h>
// Solution - Plain Approach - O(n)
int main() {
    // Init.
    
    int length, m;
    scanf("%d %d", &length, &m);
    
    int road[length + 2];
    for (int i = 0; i <= length + 1; i++) {
        road[i] = 0;
    }
    
    int subway[m][2];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &subway[i][0], &subway[i][1]);
        

        if (subway[i][0] > subway[i][1] || subway[i][0] < 0 || subway[i][1] > length) {
            continue;
        }
        

        road[subway[i][0]] += 1;
        road[subway[i][1] + 1] -= 1;
    }
    
    int sum = 0;
    int current = 0;
    
    // Prog.
    for (int i = 0; i <= length; i++) {
        current += road[i];
        if (current > 0) {
            sum++;
        }
    }
    
    printf("%d\n", (length + 1) - sum);
    
    return 0;
}
