// Tue 0ct 21, 2025

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool isValid(char *s)
{
  int len = strlen(s);
  if (len % 2 == 1 || s[0] == '}' || s[0] == ']' || s[0] == ')'
      || s[len - 1] == '{' || s[len-1] == '[' || s[len -1] ==  '(')
    return false;
  char temp[len];
  int idx = 0;
  for (int i = 0; i < len; i++) {
    char c = s [i];
    if (c == '{' || c == '(' || c == '[') {
      temp[idx] = c;
      idx ++;
    }
    if (c == '}' || c == ')' || c == ']') {
      if (idx == 0)
        return false;
      if (   (c == '}' && temp[idx - 1] == '{')
          || (c == ')' && temp[idx - 1] == '(')
          || (c == ']' && temp[idx - 1] == '[')) {
        idx--;
      }
      else {
        return false;
      }
    }
  }
  if (idx == 0)
    return true;
  else
    return false;
}

int main(void)
{
  char str[] = "()))";
  if (isValid(str))
    printf("TRUE\n");
  else
    printf("FALSE\n");
  return 0;
}
