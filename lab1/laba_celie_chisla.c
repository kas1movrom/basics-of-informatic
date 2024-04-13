#include <stdio.h>

void lesser_number(int n, int m);

int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	if (n < m)
	{
		lesser_number(n, m);
	}
	else
	{
		lesser_number(m, n);
	}
	return 0;
}

void lesser_number(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		if ((n % i == 0) && (m % i == 0))
		{
			printf("%d ", i);
		}
	}
}
