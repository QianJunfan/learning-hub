#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// q4 - composite identity func
static uint16_t add(uint16_t a)
{
        return a+1;
}

static uint16_t sqr(uint16_t a)
{
        return a*a;
}

bool composite_id(uint16_t (*f1)(uint16_t),
                  uint16_t (*f2)(uint16_t), uint8_t x)
{
        if(f2(f1(x)) == f1(f2(x)))
                return true;

        return false;
}


int main(void)
{
        printf("q4 - %d\n", composite_id(sqr, add, 4));

        return 0;
}
