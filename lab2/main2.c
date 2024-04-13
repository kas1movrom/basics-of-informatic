#include <stdio.h>
#include <math.h>

long double Taylor_series(int n, long double x) {
	long double result = 0;
	long double element = x;
	int i = 1;
	while (i <= n - 1) {
		result += element;
		element *= (x * x / ((2 * i) * (2 * i + 1)));
		i++;
	}
	result += element;
	return result;
}

int main() {
	long double x;
	int n;
	while ((scanf("%d", &n) != 1) || (n <= 0)) {
		scanf("%*c");
		printf("\n");
	}
	printf("Enter vakue x\n");
	while (scanf("%Lf", &x) != 1) {
		scanf("%*c");
		printf("\n");
	}
	printf("%Lf", Taylor_series(n, x));
	return 0;
}
