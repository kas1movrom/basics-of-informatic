#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <readline/readline.h>
#include "func.h"

char *Individualtask(char *s);

int main()
{
    double StartTime = clock();
	char *Strings = 0;
	while (1)
	{
		Strings = (char*)readline("");
		if (!Strings)
		{
			break;
		}
		Strings = IndividualTask(Strings);
		printf("%s\n", Strings);
		free(Strings);
	}
	
    
    double EndTime = clock();
    double result = (EndTime - StartTime) / CLOCKS_PER_SEC;
    printf("%lf\n", result);
    return 0;
}
