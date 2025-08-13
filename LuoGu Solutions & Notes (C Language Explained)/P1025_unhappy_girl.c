#include <stdio.h>

// Solution - Plain Approach - O(7)

int main() {
    // Init.
    int happy   = 0;
    int current = 0;
    int school  = 0;
    int mother  = 0;
    
    // Prog.
    for (int i = 0; i < 7; i++) {
        int day     = i + 1;
        scanf("%d %d", &school, &mother);
        
        int point = school + mother;
        if (point > 8) {
            if (point > current) {
                current = point;
                happy   = day;
            }
        }
    }
    
    printf("%d\n", happy);
}

