#include <stdio.h>
int lcm(int x, int y);
int gcd(int a, int b);

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d��%d��С��������%d\n���Լ����%d\n", m, n, lcm(m, n), gcd(m, n));
	return 0;
}

int gcd(int a, int b) {
	int temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	while (temp != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int lcm(int x, int y) {
	int g, p, k;
	g = gcd(x, y);
	p = x * y / g ;
	return p;
}