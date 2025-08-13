#include <stdio.h>

// Solution - Plain Solution
int main() {
    // Init.
    int cigarette = 0;
    int required  = 0;
    int butt      = 0;
    int sucked    = 0;
    
    scanf("%d %d", &cigarette, &required);
    
    // Prog.
    for (int i = cigarette; i > 0; i--) {
        butt ++;
        
        if (butt == required) {
            butt = 0;
            i ++;
        }
        
        sucked ++;
    }
    
    printf("%d\n", sucked);
    
    return 0;
}