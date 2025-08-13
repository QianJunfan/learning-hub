#include <stdio.h>
#include <stdarg.h>

/**
* @brief Calculate the sum of any number of integers.
*/

int sum(int count, ...) {
     va_list  args;
     va_start(args, count);

     int total = 0;
     for (int i = 0; i < count; i++) {
          int number = va_arg(args, int);

          total += number;
     }

     va_end(args);

     return total;
}


int main(int argc, char *argv[]) {
     printf("result = %d\n", sum(5, 2, 3, 4, 5, 998));

     return 0;
}
