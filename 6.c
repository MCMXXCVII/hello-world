/*Упражнение 1–11: Напишите программу, печатающую гистограмму длин слов из файла ввода.
Самое лёгкое – начертить гистограмму горизонтально; вертикальная ориен-
тация требует больших усилий.*/

/*-std="c90"*/
#include <stdio.h>
int main()
	{
	char c;
	int i, j, nwhite, nother, ndigit, maxval;
	int nperdigit[10];
	nwhite = nother = ndigit = maxval = 0;
	for (i = 0; i < 10; ++i)
		nperdigit[i] = 0;
	while ((c = getchar()) != '\n')
		{
		if ('0' <= c && c <= '9')
			{
			++nperdigit[c - '0'];
			++ndigit;
			}
		else if (c == ' ' || c == '\t' || c == '_')
			++nwhite;
		else
			++nother;
		}
	for (i = 0; i < 10; ++i)
		{
		printf("%d-", i);
		for (j = 0; j < nperdigit[i]; ++j)
			putchar('|');
		putchar('\n');
		}
	printf("digits = %d\nwhite-space = %d\nnon-white-space = %d\n", ndigit, nwhite, nother);
	
	for (i = 0; i < 10; ++i)
		if (nperdigit[i] > maxval)
			maxval = nperdigit[i];
	printf("max@nperdigit = %d\n", maxval);
	for (i = 0; i < maxval; ++i)
		{
		for (j = 0; j < 10; ++j)
			if ((nperdigit[j] + i) >= maxval)
				putchar('|');
			else
				putchar(' ');
		putchar('\n');
		}
	printf("0123456789\n");
	return 0;
	}
