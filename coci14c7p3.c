#include <stdio.h>

#define MAX_N 150001

int n, a[MAX_N], b[MAX_N], c[MAX_N];
int f[MAX_N][3];


int min(int x, int y) {
	if (x < y) 
		return x;
	return y;
}
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &c[i]);
	
	return 0;
}