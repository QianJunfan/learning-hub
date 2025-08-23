// Saturday, August 23, 2025 - On vacation in Anji, Zhejiang.

#include <stdio.h>
#include <stdbool.h>

static void asw(int i, bool isbreak) {
     if (isbreak) {
          printf("~ q%d asw:\n", i);
     } else {
          printf("~ q%d asw: ", i);
     }
}

// q4 - falling factorial
void falling(int n, int k) {
     // bdry
     if (k <= 0 || n <= 0) {
          asw(4, false);
          printf("1\n");
          return;
     }

     // init
     int num = n;
     int ans = num;
     // prog
     for (int i = 0; i < k-1; i++) {
          ans *= num - 1;
          num --;
     }

     asw(4, false);
     printf("%d\n", ans);
}

// q5 - divisible by k
void divisible_by_k(int n, int k) {
     // bdry
     if (n < k) {
          asw(5, false);
          printf("0\n");
          return;
     }

     // init
     int num = 0;
     int cur = 0;
     // prog
     asw(5, false);
     while (num < n) {
          cur = num * k;
          if (num * k > n) {
               break;
          }

          printf("%d, ", cur);

          num ++;
     }

     printf("\n");
}

// q6 - double eights
void double_eights(int n) {
     // bdry
     if (n / 10 == 0) {
          asw(6, false);
          printf("False\n");
          return;
     }

     // init
     int  num  = n;
     int  cur  = 0;
     int  next = 0;
     bool is_double = false;
     // prog

     while (num != 0) {
          cur  = num % 10;
          num /= 10;
          next = num % 10;

          if (cur == next && cur == 8) {
               is_double = true;
          }
     }


     asw(6, false);
     if (is_double) {
          printf("true\n");
     } else {
          printf("false\n");
     }
}

// q7 - two of three
int find_max(int i, int j, int k) {
     if (i > j && i > k) return i;
     if (j > i && j > k) return j;
     if (k > i && k > j) return k;

     return -1; // return -1 to avoid warning 
}

int find_min(int i, int j, int k) {
     if (i < j && i < k) return i;
     if (j < i && j < k) return j;
     if (k < i && k < j) return k;

     return -1; // return -1 to avoid warning 
}

int two_of_three(int i, int j, int k) {
     return i*i + j*j + k*k - find_max(i, j, k) * find_max(i, j, k);
}

// q8 - middle number
int middle_number(int i, int j, int k) {
     return i + j + k - find_max(i, j, k) - find_min(i, j, k);
}


// q9 - largest factor
void largest_factor(int n) {
     // bdry
     if (n <= 1) {
          return;
     }

     // init
     int cur = n; 

     // prog
     asw(9, false);
     while (cur > 0) {
          cur --;
          if (n % cur == 0) {
               printf("%d\n", cur);
               break;
          } 
     }
}

// q10 - multiple
int gcd(int a, int b) {
     if (b == 0) return a;
     
     return gcd(b, a % b);
}
int multiple(int a, int b) {
     return a / gcd(a, b) * b;
}


int main(void) {
     /* q4  */ falling(6, 3);
     /* q5  */ divisible_by_k(10, 2);
     /* q6  */ double_eights(12345);
     /* q7  */ asw(7, false); printf("%d\n", two_of_three(10, 2, 8));
     /* q8  */ asw(8, false); printf("%d\n", middle_number(1, 2, 3));
     /* q9  */ largest_factor(15);
     /* q10 */ asw(10, false); printf("%d\n", multiple(3, 4));
     return 0;
}
