#include <stdio.h>
#include <stdlib.h>
#define StrVowels "EeYyUuOoAaIi"

int MyStrlen(char *str) {
	int len;
	for (len = 0; str[len]; len++);
	return len;
} 

char *MyStrcat(char *dest, char *source) {
	char *ptr;
	for (ptr = dest; *ptr; ptr++);
	for (int i = 0; (ptr[i] = source[i]); i++);
	return dest;
}

char *MyStrchr(char *str, int n) {
	char *ptr;
	for (ptr = str; *ptr && *ptr != n; ptr++);
	return *ptr? ptr : NULL;
}

/*int MyStrlen(const char *str)
{
	if (*str)
	{
		return MyStrlen(++str) + 1;
	}
	else
	{
		return 0;
	}
}

char *MyStrchr(const char *str, int c)
{
    int i = 0;
    while (str[i] && str[i] != c)
    {
        ++i;
    }
    if (c == str[i])
    {
        return (char*)str + i;
    }
    else
    {
        return NULL;
    }
}

char *MyStrcat(char *destination, const char *source)
{
    char *ptr = destination + MyStrlen(destination);
    while (*source != '\0')
    {
        *ptr++ = *source++;
    }
    *ptr = '\0';
    return destination;
}*/

char *MyGetstr() {
    int n, len = 0;
    char *ptr = (char*)malloc(sizeof(char));
    *ptr = 0;
    char buf[81];
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            free(ptr);
            ptr = NULL;
        }
        if (n == 0) {
            scanf("%*c");
        }
        if (n > 0) {
            len += MyStrlen(buf);
            ptr = (char*)realloc(ptr, len + 1);
            MyStrcat(ptr, buf);
        }
    } while (n > 0);
    return ptr;
}

char *IndividualTask(char *s) {
    int j = 0;
    for (int i = 0; s[i]; i++) {
        if (!MyStrchr(StrVowels, s[i])) {
            s[j++] = s[i];
        }
    }
    s[j] = 0;
	int k = 1;
	for (int i = 1; s[i] != 0; i++) {
		if ((s[i] == ' ') && (s[i - 1] == ' ')) continue;
		s[k++] = s[i];
	}
	if (s[k - 1] == ' ') k--;
	s[k] = 0;
    return s;
}
