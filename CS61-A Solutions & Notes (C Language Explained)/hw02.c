// We did our first assignment together.
// This was CS61A's hw02, and it's the first time my little one learned to write recursion.
// Fri Oct, 10

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>

int16_t add(int16_t a, int16_t b)
{
        return a + b;
}

int16_t mul(int16_t a, int16_t b)
{
        return a * b;
}

int16_t square(int16_t x)
{
        return x * x;
}

int16_t identity(int16_t x)
{
        return x;
}

int16_t triple(int16_t x)
{
        return 3 * x;
}

int16_t increment(int16_t x)
{
        return x + 1;
}

// q1 - product
int16_t product(int8_t n, int16_t (*op)(int16_t))
{
        int16_t tmp = 1;
        for (int8_t i = 1; i <= n; i++)
                tmp *= op(i);
        return tmp;
}

int16_t product_rec(int8_t n, int16_t (*op)(int16_t))
{
        // bdry
        if (n == 0)
                return 1;
        
        return op(n) * product_rec(n-1, op); 
}

// q2 - accumulate
int16_t acc(int16_t (*fuse)(int16_t,int16_t),
            int8_t start, int8_t n, int16_t (*op)(int16_t))
{
        if (n == 0)
                return start;
        return acc(fuse, fuse(start, op(n)), n-1, op);
}

int main(void)
{
        printf("q1: %d\n", product_rec(5, square));
        printf("q2: %d\n", acc(mul, 2, 3, square));
        return 0;
}
        
