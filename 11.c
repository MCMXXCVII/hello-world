/*-std=c90*/
// (_)
// -_ +_ !_ (cast)_
// _*_ _/_ _%_
// _+_ _-_
// _>=_ _>_ _<=_ _<_
// _==_ _!=_
// _&&_
// _||_
// _=_
#include <stdio.h>
#define LIM 25

int main()
{
	char s[LIM];
	//prnascii();
	getline(s, LIM);
	//printf("%x\n", htoi(s));
	//squeeze(s, " abcdefg\t");
	//printf("%s\n", s);
	//printf("%d\n", srchposany(s, " abcdefg\t"));
}

srchposany(s1, s2)
char s1[], s2[];
{
	int i, j;
	for (i = 0; s1[i] != '\0'; ++i)
		for (j = 0; s2[j] != '\0'; ++j)
			if (s2[j] == s1[i])
				return i;
	return -1;
}


squeeze(s1, s2)
char s1[], s2[];
{
	int i, j, k, iss2;
	for (i = j = 0; s1[i] != '\0'; ++i)
	{
		for (iss2 = k = 0; s2[k] != '\0'; ++k)
			if (s2[k] == s1[i])
			{
				iss2 = 1;
				break;
			}
		if (!iss2)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
	return 0;
}

int prnascii()
{
	int i;
	for (i = 0; i < 256; ++i)
		printf("%d - %c\n", i, i);
	return 0;
}

int atoi(s)
char s[];
{
	int n = 0, i;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = n * 10 + s[i] - '0';
	return n;
}

int htoi(s)
char s[];
{
	int n = 0, i, isdigit;
	for (i = 0; (isdigit = s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F'); ++i)
		{
			if (isdigit)
				n = n * 0x10 + s[i] - '0';
			else
				n = n * 0x10 + 0xa + s[i] - 'A';
		}
	return n;
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

int prnplumin(n)
int n;
{
	printf("%d %d\n", -n, +n);
	return 0;
}

int readpirnln(lim)
int lim;
{
	int i, c;
	char s[lim];
	for (i = 0; i <= lim; ++i)
		s[i] = 0;
	for (i = 0; !(i >= lim - 1 || (c = getchar()) == '\n' || c == EOF); ++i)
		s[i] = c;
	s[i] = '\0';
	printf("%s\n", s);
	return 0;
}
