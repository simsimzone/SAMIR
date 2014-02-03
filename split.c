#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** str_split(char *, char *);
int str_any_char(char *, char);
#define MAXWORD 100

int main(int argc, char **argv)
{

	char *delimeters = ":";
	char word[MAXWORD];
	char *input = word;
	int c;
	int color = 1;
	printcolor(color++);
	while ((c = getchar()) != EOF)
	{
		if (str_any_char(delimeters, c) || c == '\n')
		{
			*input = '\0';
			printf("%-20s", word);
			input = word;
			if (c == '\n')
				putchar(c);
			if (color>7)
				color = 1;
			printcolor(color++);
		}
		else
		{
			*input++ = c;
		}
	}
	printcolor(7);
	putchar('\n');
}

printcolor(int i)
{
	char command[8];
	sprintf(command, "%c[%dm", 0x1B, i + 30);
	printf(command);
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
