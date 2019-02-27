#include <stdio.h>
#include <string.h>

#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)

int main() {
	char s[100]; 
	int f[27];
	for (int i = 0; i < 27; ++i)
		f[i] = 0; 
	fgets(s, 100, stdin);
	//printf("%s\n", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'a' + 1;
		//printf("%d\n", c);
		for (int j = 0; j < c; ++j)
			f[c] = max(f[c], f[j] + 1);
	}
	int mx = 0;
	for (int i = 0; i <= 26; ++i) {
		mx = max(mx, f[i]);

	}
	printf("%d\n", 26 - mx);
  	return 0;
}
