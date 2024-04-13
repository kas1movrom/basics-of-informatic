#include <stdio.h>
#include <math.h>

int Tay_series(long double e, long double x, long double *result) {
	char a = 1;
	int i = 1;
	long double p = x;
	while (a) {
		p *= (x * x / ((2 * i) * (2 * i + 1)));
		*result += p;
		if (p < e) {
			a = 0;
		}
		i++;
	}
	return i;
}

long double proverka(long double x) {
	return (expl(x) - expl(-x)) / 2;
}

int main() {
	long double x, e;
	printf("Enter value :\n");
	while (scanf("%Lf", &x) != 1) {
		scanf("%*c");
		printf("\n");
	}
	printf("Enter value e\n");
	while ((scanf("%Lf", &e) != 1) || (e <= 0)) {
		scanf("%*c");
		printf("\n");
	}
	long double sum = x;
	printf("%Lf\n", proverka(x));
	printf("%d", Tay_series(e, x, &sum));
	printf("%Lf", sum);
	return 0;
}
