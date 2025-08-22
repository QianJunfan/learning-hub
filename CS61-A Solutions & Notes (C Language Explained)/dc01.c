// Saturday, August 23, 2025 - On vacation in Anji, Zhejiang.
#include <stdio.h>
#include <stdbool.h>

// Q1   - Race
// Disc - The 'while' loop condition 'tottoise - hare' is a logic error.
//        It only stops when they are at the exact same position,
//        causing an infinite loop when the tortoise passes the hare.
int race(int x, int y) {
     // Bdry
     if (y < x || y >= 2*x) return 0;

     // Init
     int tortoise = 0,
         hare     = 0,
         minutes  = 0;

     // Prog
     while (minutes == 0 || tortoise < hare) {
          tortoise += x;

          if (minutes % 10 < 5) hare += y;

          minutes ++;
     }
     return minutes;
}

// Q2 - Fizzbuzz
void fizzbuzz(int n) {
     // Bdry
     if (n <= 0) return;

     // Init
     int number = 1;
     
     // Prog
     while (number <= n) {
          if (number % 3 == 0 && number % 5 == 0) printf("     fizzbuzz\n");
          if (number % 3 == 0 && number % 5 != 0) printf("     fizz\n");
          if (number % 3 != 0 && number % 5 == 0) printf("     buzz\n");
          if (number % 3 != 0 && number % 5 != 0) printf("     %d\n", number);
         
          number += 1;
     }
}

// Q3 - Is a number prime
void is_prime(int number) {
     // Bdry
     if (number <= 0) return;

     // Init
     bool isPrime = false;
     
     // Prog
     for (int i = 2; i < number; i++) {
          if (number % i == 0) isPrime = true;
     }

     if (isPrime) {
          printf("True\n");
     } else {
          printf("False\n");
     }
}


// Q4 - Unique Digits
int unique_digits(int n) {
     // Bdry
     if (n == 0) return 1;

     // Init
     int arr[10] = {0};
     int num = n;

     // Prog
     while (num > 0) {
          int digit  = num % 10;
          arr[digit] = 1;
          num /= 10;
     }

     int count = 0;
     for (int i = 0; i < 10; i++) {
          if (arr[i] == 1) count++;
     }

     return count;
}

// Q5 - Ordered Digits
void ordered_digits(int x) {
     // Bdry
     if (x / 10 == 0) {
          printf("Q5 Result - True\n");
     } 

     // Init
     bool is_ordered = true;
     int  num  = x;
     int  curr = 0;
     int  next = 0;

     // Prog 
     while (num > 0) {
          curr = num % 10;
          num /= 10;
          next = num % 10;
          if (curr < next) is_ordered = false;
     }

     if (is_ordered) {
          printf("Q5 Result - True\n");
     } else {
          printf("Q5 Result - false\n");
     }
}

int main(void) {
     // Q1
     printf("Q1 Result - %d\n", race(4, 6));
     
     // Q2
     printf("Q2 Result -\n");
     fizzbuzz(16);

     // Q3
     printf("Q3 Result - ");
     is_prime(6);
     
     // Q4
     printf("Q4 Result - %d\n", unique_digits(123441));

     // Q5
     ordered_digits(12345691);
     return 0;
}
