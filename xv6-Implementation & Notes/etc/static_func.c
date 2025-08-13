#include <stdio.h>

void count_calls() {
     static int call_count = 0;
     call_count++;

     printf("this function has been called %d times.\n", call_count);
}


int main() {
     count_calls();
     count_calls();
     count_calls();


     return 0;
}
