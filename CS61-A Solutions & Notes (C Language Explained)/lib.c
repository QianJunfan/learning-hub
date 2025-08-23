/**
* @brief gcd - fetch Greatest Common Divisor
* @param a   - an integer
* @param b   - another integer
*/
int gcd(int a, int b) {
     if (b == 0) return a;

     return gcd(b, a % b);
}
