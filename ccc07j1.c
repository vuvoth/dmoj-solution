#include <stdio.h>

int main() {
  int a, b, c; 
  
  scanf("%d%d%d", &a, &b, &c);
  int A = (a > b) ? a : b;
  int B = (b > c) ? b : c;
  int C = (A > B) ? A : B;
  if (C == a) 
    C = B;
  else if (C == c) 
    C = A;
  else 
    C = (a > c) ? a : c;
  printf("%d\n", C);

  return 0;
}
