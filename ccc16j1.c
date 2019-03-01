#include <stdio.h>

int main()
{
  char c;
  int cnt = 0;
  while (scanf("%c", &c) == 1) {
    if (c == 'W')
      cnt++;
  }
  if (cnt == 0)
    printf("-1\n");
  else if (cnt <= 2) 
    printf("3\n");
  else if (cnt <= 4)
    printf("2\n");
  else 
    printf("1\n");
  return 0;
}
