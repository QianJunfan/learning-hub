#include <stdio.h>

void callback_func(int data) {
     printf("CALLBACK - receive: %d\n", data);
}

void host_func(void (*callback_ptr)(int), int value) {
     // void indicates that the function pointed to by this pointer has no retrun value,
     // (*callback_ptr) signifies that callback_ptr is a pointer,
     // (int) meas that the function pointed to by this pointer accepts an interger-type parameter.
     callback_ptr(value);
}

int main(void){
     host_func(callback_func, 123);

     return 0;
}
