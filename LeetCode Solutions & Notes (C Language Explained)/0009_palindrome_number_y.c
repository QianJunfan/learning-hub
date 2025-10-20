#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x)
{
  int num = x;
  if (x == 0 || (x > 0 && x % 10 != 0)) {
    int half= 0;
    while (x > half) {
      half = half * 10 + x % 10;
      x /= 10;
    }
    if (x == half || x == half / 10)
      return true;
  }
  return false;
} 
