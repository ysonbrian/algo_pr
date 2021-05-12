#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if(x < 0)
        return false;
    if(x == 0)
        return true;
    int result = 0, before = x;
    while(x) {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result == before;
}

int main(void){
  int n;
  scanf("%d", &n);
  printf("%s ",isPalindrome(n) ? "true" : "false");
  return 0;
}
