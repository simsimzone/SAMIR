#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** str_split(char *, char *);
int main()
{
	printf("\n");
	char *delimeters = ":,";
	char **result = str_split("sami:abdelgadir:mohammed", ":");
	while (*result)
	{
		printf("%s\t", *result++);
	}
}

char *str_dup(const char *);
int str_any_char(char *, char);

char** str_split(char *str, char *delimeters)
{
	char **result;
	char *input = str_dup(str);		/* so as to work with a copy of str and let str be unmodified */
	char *inp = input;
	int count = 0;
	while (*inp)
	{
		if (str_any_char(delimeters, *inp++))
			count++;
	}
	count += 2;		/* extra for the NULL */
	result = (char**) malloc(sizeof(char*) * count);
	if (result)
	{
		char* token = strtok(input, delimeters);
		int i = 0;
		while (token)
		{
			*(result + i++) = str_dup(token);
			token = strtok(NULL, delimeters);
		}
		*(result + i) = NULL;
	}
	return result;
}

char *str_dup(const char *s) {
	char *d = (char *)malloc(strlen(s) + 1);
	if (d)
		strcpy(d, s);
	return d;
}

/* searches for c in s */
int str_any_char(char *s, char c)
{
	char *s1 = s;
	while (*s1)
		if (*s1++ == c)
			return 1;
	return 0;
}
