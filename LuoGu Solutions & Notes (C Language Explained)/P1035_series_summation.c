#include <stdio.h>
#include <math.h>
// Solution 1 - Plain Solution - O(e^k)
void series_summation_plain() {
    // Init.
    int n = 1;
    int k = 0;
    double num = 0.0;
    scanf("%d", &k);
    
    // Prog.
    while (1) {
        num += 1.0/n;
        if (num > k) {
            break;
        }
        n++;
    }
    
    printf("%d", n);
}


// Solution 2 - Binary Search - O(log e^k)
double harmonic(int n) {
    double sum = 0.0;
    
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }
    
    return sum;
}
void series_summation_binary_search() {
    // Init.
    scanf("%d", &k);
    
    // Prog.
    int low    = 1;
    int high   = (int)exp(k + 1) + 1;
    int answer = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (harmonic(mid) > k) {
            answer = mid;
        } else {
            low = mid + 1;
        }
    }
    
    printf("%d\n", answer);

}
