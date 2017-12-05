/*Упражнение 1–12: Напишите программу преобразования прописных букв из файла ввода в
строчные, используя при этом функцию lower(c), которая возвращает зна-
чение c, если c – не буква, и значение соответствующей строчной буквы, если
c – буква.*/
/*-std="c90"*/
#include <stdio.h>

main()
	{
	char c;
	while ((c = getchar()) != '\n')
		putchar(lower(c));
	putchar('\n');
	return 0;
	}

lower(c)
char c;
	{
	if ('A' <= c && c <= 'Z')
		return (c - ('A' - 'a'));
	else
		return c;
	}

exmain()
	{
	int i;
	for (i = 0; i < 10; ++i)
		printf("%6d %6d %6d\n", 1, power(2, i), power(3, i));
	return 0;
	}
	
power(x, n)
int x, n;
	{
	int p;
	for (p = 1; 0 < n; --n)
		p = p * x;
	return p;
	}
