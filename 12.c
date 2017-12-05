/*-std="c89"*/
#include <stdio.h>
#include <string.h>
#define LIM 32

int rightrot(x, n)
unsigned x, n;
{
	int i;
	for (i = 0; !(~((unsigned)~0 >> 1) & x) && i < sizeof (int) * 8; ++i)
		x <<= 1;
	x >>= i;
	for (; n; --n)
	{
		if (x & 1)
		{
			x = x >> 1;
			x = x | (~((unsigned)~0 >> (1)) >> i); /* " >> i" makes it humane*/
		}
		else
			x >>= 1;
	}
	return x;
}

int wordlength()
{
	/*return (sizeof (int) * 8); //too easy :)*/
	unsigned i, x;
	x = 1;
	for (i = 0; x; ++i)
		x <<= 1;
	return i;
}

int getbits(x, p, n)
unsigned x, p, n;
{
	return (x >> p & ~(~0 << n));
}

int invert(x, p, n)
{
	return (x ^ (~(~0 << n) << p));
}

int getbitsltr(x, p, n)
unsigned x, p, n;
{
	int i;
	for (i = 0; !(~((unsigned)~0 >> 1) & x); ++i)
		x = x << 1;
	return (x << p >> (sizeof (int) * 8 - n));
}

int printbinary(x)
unsigned x;
{
	/*int i = 0, len, buf;
	char s[sizeof (int) * 8 + 1];
	while (x)
	{
		if (x & 1)
			s[i] = '1';
		else
			s[i] = '0';
		x = x >> 1;
		++i;
	}
	s[i] = '\0';
	len = i;
	for (i = 0; i < len / 2; ++i)
	{
		buf = s[i];
		s[i] = s [len - 1 - i];
		s[len - 1 - i] = buf;
	}
	printf("%s\n", s); //too long*/
	int i;
	for (i = 0; !(~((unsigned)~0 >> 1) & x) && i < sizeof (int) * 8; ++i)
		x <<= 1;
	for (i = sizeof (int) * 8 - i; i; --i) /* " - i" excludes leading zeroes*/
		{
			if (~((unsigned)~0 >> 1) & x)
				putchar('1');
			else
				putchar('0');
			x <<= 1;
		}
	putchar('\n');
	return 0;
}

int my_getline(s, lim)
char s[];
int lim;
{
	int i, c;
	for (i = 0; !(i >= lim - 1 || (c = getchar()) == '\n' || c == EOF); ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}

int atoi(s)
char s[];
{
	int n = 0, i;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = n * 10 + s[i] - '0';
	return n;
}

int strreverse(s)
char s[];
{
	int len, i, buf;
	len = strlen(s);
	for (i = 0; i < len / 2; ++i)
	{
		buf = s[i];
		s[i] = s [len - 1 - i];
		s[len - 1 - i] = buf;
	}
	return 0;
}

int my_strlen(s, lim)
char s[];
int lim;
{
	int i;
	for (i = 0; i < lim && s[i] != '\0'; ++i)
		;
	return i;
}

int bitcount(x)
unsigned x;
{
	int n;
	/*for (n = 0; x; x >>= 1)
		if (x & 1)
			++n;
	return n;*/
	for (n = 0; x; ++n)
		x &= x - 1;
	return n;
}

int main()
{
	unsigned p, n, x;
	x = 0167;
	p = 2;
	n = 3;
	/*char s[LIM + 1] = "";
	my_getline(s, LIM);
	x = atoi(s);
	printf("got it: %d\n", x);*/
	printf("bit count: %d\n", bitcount(x));
	printf("word length: %d\n", wordlength());
	printbinary(x);
	printbinary(getbits(x, p, n));
	printbinary(getbitsltr(x, p, n));
	printbinary(rightrot(x, 1));
	printbinary(invert(x, p, n));
	return 0;
}
