#include <stdio.h>
#define N 100
#define M 100

int main() {
	int a[N], i, j, n, b[M], m = 0, s = 0, h;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		a[i] = i;
	}
	for (i = 1; i <= n; i++) {
		if (i <= 10) {
			if (a[i] % 7 != 0) {
				m = m + 1;
				b[m] = a[i];
			}
		} else {
			h = a[i] / 10;
			j = a[i] % 10;
			if (h != 7 && j != 7 && a[i] % 7 != 0) {
				m = m + 1;
				b[m] = a[i];
			}
		}
	}
	for (i = 1; i <= m; i++) {
		s = s + b[i] * b[i];
	}
	printf("%d", s);
	return 0;
}