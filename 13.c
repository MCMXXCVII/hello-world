/* -std="c89" */
#include <stdio.h>
#define LIM 25

int initarray(s, lim)
char s[], lim;
{
	int i;
	for (i = 0; i < lim; ++i)
		s[i] = (i == lim - 1) ? '\0' : ('A' + i);
	return 0;
}

int printarray(s, lim)
int s[], lim;
{
	int i;
	for (i = 0; i < lim; ++i)
		printf("%4d%c", s[i], (i % 10 == 9 || i == lim - 1) ? '\n' : ' ');
	return 0;
}

int printarray2(s, lim)
int s[], lim;
{
	int i;
	for (i = 0; i < lim; ++i)
	{
		printf("%4d", s[i]);
		if (i % 10 == 9 || i == lim - 1)
			putchar('\n');
		else
			putchar(' ');
	}
	return 0;
}

int lower(s, lim)
char s[];
int lim;
{
	int i;
	for (i = 0; i < lim && s[i] != '\0'; ++i)
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' + 'a' : s[i];
	return 0;
}

int main()
{
	char s[LIM];
	initarray(s, LIM);
	printf("%s\n", s);
	lower(s, LIM);
	printf("%s\n", s);
	return 0;
}
