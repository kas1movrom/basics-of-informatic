#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include "func.h"

int main()
{
	int StartTime = clock();
	char *Strings = " ";
	while (1)
	{
			printf("Enter your string:\n");
			Strings = MyGetstr();
		if (!Strings)
		{
			break;
		}
		Strings = IndividualTask(Strings);
		printf("%s\n", Strings);
		free(Strings);
	}
	int EndTime = clock();
	double RunTime = ((double)EndTime - (double)StartTime) / CLOCKS_PER_SEC;
	printf("Время работы программы: %lf\n", RunTime);
    return 0;
}
