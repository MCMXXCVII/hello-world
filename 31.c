/* -std="c89" */
#include <stdio.h>
#include <string.h>
#define LIM 25

int atoi(s)
char s[];
{
	int i, sign, n;
	for (i = 0; s[i] == ' ' || s[i] == '\t' || s[i] == '\t'; ++i)
		;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
		sign = (s[i++] == '-') ? (-1) : 1;
	n = 0;
	while (s[i] >= '0' && s[i] <= '9')
			n = n * 10 + s[i++] - '0';
	return (sign * n);
}

int readchararr(s, lim)
char s[];
short unsigned int lim;
{
	int len = 0;
	char c;
	while ((c = getchar()) != '\n' && c != EOF && len < lim)
	{
		s[len] = c;
		++len;
	}
	return len;
}

int shellchararr(s, len) /* !get it - shell sort */
char s[];
int len;
{
	int /*gap, */i, j, buf;

	/*for (gap = len / 2; gap > 0; gap /= 2)
		for (i = gap; i < len; i++)
			for (j = i - gap; j >= 0 && s[j] > s[j + gap]; j -= gap)
			{
				buf = s[j];
				s[j] = s[j + gap];
				s[j + gap] = buf;
			}*/

	/*gap = len / 2;
	while (gap > 0)
	{
		i = 0;
		while (i < len)
		{
			j = i - gap;
			while (j >= 0)
			{
				if (s[j] > s[j + gap])
				{
					buf = s[j];
					s[j] = s[j + gap];
					s[j + gap] = buf;
				}
				printf("len=%d gap=%d j=%d i=%d %s\n", len, gap, j, i, s);
				j -= gap;
			}
			++i;
		}
		gap /= 2;
	}*/

	for (i = 0; i < len; ++i)
		for (j = i - 1; j >= 0; --j)
			if (s[j] > s[j + 1])
			{
				buf = s[j];
				s[j] = s[j + 1];
				s[j + 1] = buf;
			}

	return 0;
}

int reversestring(s)
char s[];
{
	int i, j;
	char c;
	for (i = 0, j = strlen(s) - 1; i < j; ++i, --j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	return 0;
}

int expand(s1, s2)
char s1[], s2[];
#define RANGE_FOUND ((c = s1[i - 1]) >= '0' && s1[i - 1] <= '9' && s1[i + 1] >= '0' && s1[i + 1] <= '9' && s1[i - 1] <= s1[i + 1]) || (s1[i - 1] >= 'A' && s1[i - 1] <= 'Z' && s1[i + 1] >= 'A' && s1[i + 1] <= 'Z' && s1[i - 1] <= s1[i + 1]) || (s1[i - 1] >= 'a' && s1[i - 1] <= 'z' && s1[i + 1] >= 'a' && s1[i + 1] <= 'z' && s1[i - 1] <= s1[i + 1])
{
	int i, j, len;
	char c;
	len = strlen(s1);
	for (i = 0, j = 0; i < len; ++i, ++j)
	{
		if (s1[i] == '-' && i > 0 && i < len - 1)
		{
			if (RANGE_FOUND)
			{
				while (c <= s1[i + 1])
					s2[j++ - 1] = c++;
				++i;
			}
			j -= 2; /*?does anyone put it here before getting a mistake in calculations*/
		}
		else
			s2[j] = s1[i];
	}
	return 0;
}

int itoa(n, s)
int n;
char s[];
{
	int i, sign;
	unsigned nn = n;
	if ((sign = n) < 0)
		nn = -n;
	i = 0;
	do
	{
		s[i++] = nn % 10 + '0';
	}
	while ((nn /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reversestring(s);
	return 0;
}

int itob(n, s)
int n;
char s[];
{
	unsigned i = 0, nn = n;
	do
	{
		s[i++] = nn % 2 + '0';
	}
	while ((nn /= 2) > 0);
	s[i] = '\0';
	reversestring(s);
	return 0;
}

int itoh(n, s)
int n;
char s[];
{
	unsigned i = 0, nn = n;
	do
	{
		s[i++] = ((n = nn % 0x10) > 0x9) ? n - 0xA + 'A': n + '0';
	}
	while ((nn /= 0x10) > 0);
	s[i] = '\0';
	reversestring(s);
	return 0;
}

int itoaw(n, s, w)
int n;
char s[];
unsigned char w;
{
	unsigned i = 0, 
	nn = (n < 0) ? -n : n;
	do
	{
		s[i++] = (nn % 10) + '0';
	}
	while ((nn /= 10) > 0);
	do
	{
		s[i++] = '0';
	}
	while (i < (w - 1));
	s[w - 1] = (n < 0) ? '-' : '0';
	s[w] = '\0';
	reversestring(s);
	return 0;
}

int getline(s, lim)
char s[];
int lim;
{
	int i, c;
	for (i = 0; !(i >= lim - 1 || (c = getchar()) == '\n' || c == EOF); ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
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

int remendblank(s)
char s[];
{
	unsigned char len = my_strlen(s, LIM);
	while (len-- >= 0) /*while (len-- >= 0 && (s[len] == ’ ’ || s[len] == ’\t’ || s[len] == ’\n’));*/
		if (s[len] != ' ' && s[len] != '\t' && s[len] != '\n')
			break;
	s[len + 1] = '\0';
	return 0;
}

int prnuniq(s, sa, lim)
char s[], sa[];
int lim;
{
	unsigned char len = strlen(s), new = 0, i;
	for (i = 0; i <= len; ++i)
		if (sa[i] != s[i])
		{
			sa[i] = s[i];
			new = 1;
		}
	if (new) 
		printf("%s\n", s);
	return 0;
}

int main()
{
	goto nextline;
	nextline:;
	char s[LIM + 1] = "", 
	s1[LIM + 1] = "foo 0-9 A-M n-z bar  ", 
	s2[10 * LIM] = "", 
	s3[LIM] = "", 
	sa[LIM + 1] = "";
	int len, 
	n, 
	z = -123; /*~((unsigned)~0 >> 0) - 0*/
	expand(s1, s2);
	printf("%s -> %s\n", s1, s2);
	len = readchararr(s, LIM);
	shellchararr(s, len);
	printf("sorted string: %s\n", s);
	printf("extracted number: %d\n", (n = atoi(s)));
	itoaw(z, s3, 6);
	printf("number %d to string: %s\n", z, s3);
	reversestring(s);
	printf("string reversed: %s\n", s);
	printf("ok google ");
	getline(s, LIM);
	remendblank(s);
	printf("got it %s\n", s);
	while (getline(s, LIM))
		prnuniq(s, sa, LIM);
	return 0;
}
