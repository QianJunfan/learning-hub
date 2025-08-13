#include <stdio.h>

typedef void(*EventHandler)();

// a static variable to store the function pointer;
static EventHandler g_on_click_handler = NULL;

void register_on_clic_event(EventHandler handler) {
     g_on_click_handler = handler;
}

void simulate_click() {
     if (g_on_click_handler != NULL) {
          g_on_click_handler();
     }
}

void func() {
     printf("func()");
}


int main() {
     register_on_clic_event(func);

     simulate_click();

     return 0;
}
