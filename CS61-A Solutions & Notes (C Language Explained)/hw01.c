// Friday, August 22, 2025 - On vacation in Anji, Zhejiang.
#include <stdio.h>

// Q1 - A_Plus_Abs_B
int a_plus_abs_b(int a, int b) {
	if (b < 0) b = -b;
	return a + b;
}


// Q2 - Heilstone
void heilstone(int num) {
	printf("        - %d\n", num);
	if (num == 1)     return;
	if (num % 2 == 0) return heilstone(num / 2);
	if (num % 2 != 0) return heilstone(num * 3 + 1);
}

// Q3 - Product
int npow(int n, int term) {
	if (term == 0) return 1;
	return n * npow(n, term - 1);
}

int product(int n, int term) {
	int result = 1;
	for (int j = 1; j <= n; j++) {
		result = npow(j, term) * result;
	}

	return result;
}

// Q4 - Make_Repeater
typedef int (*func_pointer)(int);
int square(int x) {
	return x * x;
}
int increment(int x) {
	return x += 1;
}
int repeater(func_pointer func, int n, int x) {
	// Bdry
	if (func == NULL) return -1;
	if (n < 0)       return -1;
	
	int cur = x;
	for (int i = 0; i < n; i++) {
		cur = func(cur);
	}

	return cur;
}
int main(void) {
	// Q - 1
	printf("Q1 Result - %d\n", a_plus_abs_b(9, -9));
	
	// Q - 2
	printf("Q2 Result -\n");
	heilstone(10);

	// Q - 3
	printf("Q3 Result - %d\n", product(3, 3));

	// Q - 4
	printf("Q4 Result - %d\n", repeater(square, 3, 5));

	return 0;
}

