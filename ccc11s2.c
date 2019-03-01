#include <stdio.h>

#define MAX_N 10000

int n;
char correct_answer[MAX_N], student_answer[MAX_N];
int main()
{
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i)
    scanf("%c\n", &student_answer[i]);
  for (int i = 0; i < n; ++i) 
    scanf("%c\n", &correct_answer[i]);
  int ans = 0;
  for (int i = 0; i < n; ++i) 
    if (student_answer[i] == correct_answer[i])
      ans++;
  printf("%d", ans);
  return 0;
}
