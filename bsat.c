#include <stdio.h>
#include <stdlib.h>

#define MAX_D 24

int N, K;
int arr[MAX_D * 2];
long long X[(1 << MAX_D)], Y[(1 << MAX_D)];

int generate_something(int arr[], int l, int r, long long X[]) {
	// genarete all subset of arr[] from l to r and store to X[].
	int len = r - l + 1;
	long long sum;
	int id = 0;
	for (int s = 0; s < (1 << len); ++s) {
		sum = 0;
		for (int i = 0; i < len; ++i) {
			if (s & (1 << i))  {
				sum += arr[i + l];
			}
		}
		X[s] = sum;
	}
	return (int)(1 << (len));
}

int binary_search(long long *arr, int L, int R, long long value) {
	// return first index id with L <= id <= R and a[id] >= value. arr is sored. 
	int l = L, r = R;
	int m;
	while (l <= r) {
		m = (l + r) >> 1;
		if (arr[m] > value) 
			r = m - 1;
		else 
			l = m + 1;
	}
	return l;
}
  
int cmp(const void *a, const void *b) {
	return (*(long long *)a - *(long long *)b);
}
void solution(int arr[], int n, int k) {
	int size_left  = generate_something(arr, 0, n / 2, X);
	int size_right = generate_something(arr, (n / 2 + 1), n - 1, Y);
	long long ans = 0;
	qsort(X, size_left, sizeof(long long), cmp);
	qsort(Y, size_right, sizeof(long long), cmp);
	for (int i = 0; i < size_left; ++i) {
		ans += binary_search(Y, 0, size_right - 1, k - X[i]);
	}
	printf("%lld\n", ans);
}


int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
	}
	solution(arr, N, K);
	return 0;
}