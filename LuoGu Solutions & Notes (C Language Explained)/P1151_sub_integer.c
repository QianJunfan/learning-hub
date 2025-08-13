#include <stdio.h>
// Solution - Plain Solution
int main() {
    // Init.
    int is_Exist = 0;
    int integer  = 0;
    scanf("%d", &integer);
    
    // Bdry.
    if (integer == 0) {
        printf("No\n");
        return 0;
    }
    // Prog.
    for (int num = 10000; num <= 30000; num++) {
        int sub1 = num / 100;
        int sub2 = (num / 10) % 1000;
        int sub3 = num % 1000;
        if (sub1 % integer == 0 && sub2 % integer == 0 && sub3 % integer == 0) {
            is_Exist = 1;
            printf("%d\n", num);
        }
    }
    
    if (is_Exist == 0) {
        printf("No\n");
    }
    
    return 0;
}