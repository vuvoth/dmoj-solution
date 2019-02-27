#include <stdio.h>
#include <string.h>

int n, k;
int a[1000001], c[1000001];

int 
add(int *c, int v, int *d) 
{
  if (c[v] == 0) 
    *d = *d + 1;
  c[v]++;
  return *d;
}

int 
rm(int *c, int v, int *d)
{
  c[v]--;
  if (c[v] == 0) 
    *d = *d - 1;
  return *d;
}

int 
main()
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) 
    scanf("%d", a + i);
  int d = 0;
  long long ans = 0;
  memset(c, 0, sizeof(c));
  for (int L = 0, R = 0; L < n; ++L) 
    {
      while (R < n && add(c, a[R], &d) < k) 
        ++R; 
      ans += (R - L);
      if (R < n) {
        rm(c, a[R], &d);
      }
      rm(c, a[L], &d);
    }
  ans = n * 1LL * (n + 1) / 2 - ans;
  printf("%lld\n", ans);
  return 0;
}
