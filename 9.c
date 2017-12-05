/* -std="c90" */
#define LIM 10
#include <stdio.h>

main()
	{
	int len;
	char line[(LIM + 1)];
	while ((len = getline(line, LIM)) > 0)
		{
		reverse(line, len);
		printf("/%s\b", line);
		}
	return 0;
	}
	
getline(s, lim)
char s[];
int lim;
	{
	int c, i, b;
	b = 0;
	for (i = 0; (i < lim) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		{
		s[i] = c;
		if (((c == ' ') || (c == '\t')) && ((s[i-1] == ' ') || (s[i-1] == '\t')))
			{
			if (b == 0)
				++b;
			++b;
			}
		else
			b = 0;
		}
	if (c == '\n')
		{
		s[i - b] = c;
		++i;
		}
	s[i - b] = '\0';
	return (i - b);
	}
	
reverse(s, lim)
char s[];
int lim;
	{
	int i;
	char c;
	lim = lim - 2;
	for (i = 0; i <= (lim / 2); ++i)
		{
		c = s[i];
		s[i] = s[lim - i];
		s[lim - i] = c;
		}
	return 0;
	}
