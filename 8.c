/* -std="c90" */
#define LIM 10
#include <stdio.h>

main()
	{
	int len, maxlen, maxline;
	int c, i;
	maxlen = 0;
	i = 0;
	char line[(LIM + 1)];
	while ((len = getline(line, LIM)) > 0)
		{
		if (len == LIM)
			{
			printf("= %s", line);
			while ((c = getchar()) != '\n')
				{
				putchar(c);
				++len;
				}
			putchar('\n');
			++len;
			}
		if (len > maxlen)
			{
			maxlen = len;
			}
		}
	if (maxlen > 0)
		printf("- - -\n%d\n", maxlen);
	return 0;
	}
	
getline(s, lim)
char s[];
int lim;
	{
	int c, i;
	/*for (i = 0; (i < lim) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		s[i] = c;
	if (c == '\n')
		{
		s[i] = c;
		++i;
		}
	s[i] = '\0';
	return i;*/
	for (i = 0; i < lim && (c = getchar()) != EOF; ++i)
		{
		s[i] = c;
		if (c == '\n')
			{
			s[i + 1] = '\0';
			return (i + 1);
			}
		}
	s[i] = '\0';
	return i;
	}
	
copy(s1, s2)
char s1[], s2[];
	{
	int i;
	i = 0;
	while ((s2[i] = s1[i]) != '\0')
		++i;
	return i;
	}
