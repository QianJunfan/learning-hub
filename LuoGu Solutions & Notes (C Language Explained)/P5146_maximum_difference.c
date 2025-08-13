#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Wrong Solution 1 - Plain Approach - Score only 58
int main_pl_a(){
    // Init.
    int size = 0;
    scanf("%d", &size);
    if (size < 2) return 0;
    
    int *array = (int *)malloc(size * sizeof(int));
    if (!array) return 0;
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    int max     = array[0];
    int min     = array[0];
    int current = 0;
    
    
    // Prog.
    for (int i = 0; i < size; i++) {
        current = array[i];
        if (current > max) {
            max = current;
        }
        
        if (current < min) {
            min = current;
        }
    }
    
    printf("%lld\n", (long long)max - min);
    return 0;
}

// Wrong Solution 2 - Not Storing Every Data - Score only 58
int main_ns() {
    // Init.
    long long size    =  0,
              min     =  LLONG_MAX,
              max     =  LLONG_MIN,
    
              current = 0;

    scanf("%lld", &size);
    
    // Prog.
    for (int i = 0; i < size; i++) {
        scanf("%lld", &current);
        
        if (current < min) min = current;
        if (current > max) max = current;
    }
    
    printf("%lld\n", (long long)max - min);
    
    return 0;
}

// Solution - Finall Approach
int main() {
    // Init.
    int n;
    long long tmp, ans = LLONG_MIN, min;
    scanf("%d %lld", &n, &min);
    
    // Prog.
    for (int i = 2; i <= n; i++) {
        scanf("%lld", &tmp);
        
        if (tmp - min > ans) ans = tmp - min;
        if (tmp < min)       min = tmp;
    }
    
    printf("%lld", ans);
    
    return 0;
}


