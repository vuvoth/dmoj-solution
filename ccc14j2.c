#include <stdio.h>

int n;
char s[20]; 

int 
main()
{
  int A, B;
  A = B = 0;
  scanf("%d\n", &n);
  for (int i = 0; i < n ; ++i) 
    {
      scanf("%c", &s[i]);
      if (s[i] == 'A')
        A++;
      else 
        B++;
    }
  if (A == B) 
    printf("Tie\n");
  else if (A > B)
    printf("A\n");
  else 
    printf("B\n");
  return 0;
}
