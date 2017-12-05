/*-std="c90"*/
#include <stdio.h>
#define LIM 250
#define WID 25
#define TABLEN 8

main()
	{
	char line[LIM + 1];
	int len;
	for (int i = 0; i < 50; printf("%d", i++ % 8));
	putchar('\n');
	while ((len = getline(line, LIM)) > 0)
		{
		//printlinewrap(line, WID);
		//detab(line, len, TABLEN);
		entab(line, len, TABLEN);
		printf("%s", line);
		}
	}
	
getline(s, lim)
char s[];
int lim;
	{
	int c, i;
	for (i = 0; (c = getchar()) != EOF; ++i)
		{
		s[i] = c;
		if (c == '\n')
			{
			++i;
			break;
			}
		else if (i == lim - 2)
			{
			s[++i] = '\n';
			++i;
			break;
			}
		}
	s[i] = '\0';
	return i;
	}

detab(s, slen, tablen)
int slen, tablen;
char s[];
	{
	int i, j, k, tabmet, buflen, inibuflen;
	char buf[tablen];
	buflen = 0;
	tabmet = 0;
	for (i = 0; s[i] || buflen; ++i) //until s[i] != '\0' and do not stop if any in buf
		{ // ? check initial buflen
		if (!tabmet && s[i] == '\t')
			{
			tabmet = 1;
			s[i] = ' ';
			}
		else if (tabmet && i % tablen)
			{
			buf[buflen++] = s[i];
			s[i] = ' ';
			}
		else if (tabmet)
			{
			tabmet = 0;
			if (buflen)
				{
				printf("+%d added &%d shifted\n", buflen, slen + buflen - i);
				for (k = slen; k >= i; --k)
					s[k + buflen] = s[k];
				for (inibuflen = buflen; buflen > 0; --buflen)
					s[i + inibuflen - buflen] = buf[inibuflen - buflen];
				slen = slen + inibuflen;
				--i;
				}
			}
		}
	for (i = 0; s[i]; ++i)
		;
	printf(": detab done, string ends at %d\n", i);
	return 0;
	}

entab(s, slen, tablen) // ! do a block flowchart of this
char s[];
int slen, tablen;
	{
	int i, j, inspace, lastspacebegin, tabshift;
	lastspacebegin = inspace = tabshift = j = 0;
	for (i = 0; s[i]; ++i)
		{
		if (s[i] == ' ')
			{
			if (!inspace)
				lastspacebegin = i;
			inspace = 1;
			}
		else
			inspace = 0;
		s[i - tabshift] = s[i]; // rewritten when i equals lastspacebegin
		if (!((i + 1) % tablen))
			{
			if (inspace)
				{
				s[lastspacebegin - tabshift] = '\t'; // shifts too, forgot?
				tabshift += i - lastspacebegin;
				}
			inspace = 0;
			}
		}
	s[i - tabshift] = '\0';
	printf(": entab done, got length %d\n", i - tabshift);
	return 0;
	}

printlinewrap(s, wid)
char s[];
int wid;
	{
	char printbuf[wid + 1];
	int i, j, inword, lastwordbegin, lastspacebegin;
	i = 0;
	while (s[i] != '\0')
		{
		inword = 1;
		lastwordbegin = 0;
		lastspacebegin = 0;
		for (j = 0; (j <= wid) && (s[i + j] != '\0'); ++j)
			{
			printbuf[j] = s[i + j];
			if ((s[i + j] == ' ') || (s[i + j] == '\t'))
				{
				if (inword == 1)
					lastspacebegin = j;
				inword = 0;
				}
			else if (inword == 0)
				{
				lastwordbegin = j;
				inword = 1;
				}
			}
		i = i + j;
		if (s[i] == '\0')
			printbuf[j] = s[i];
		else if (inword == 0)
			{
			printbuf[lastspacebegin] = '\n';
			printbuf[lastspacebegin + 1] = '\0';
			while ((s[i] == ' ') || (s[i] == '\t'))
				++i; 
			}
		else if (lastwordbegin == 0)
			{
			printbuf[j - 2] = '-';
			printbuf[j - 1] = '\n';
			printbuf[j] = '\0';
			i = i - 2;
			}
		else
			{
			printbuf[lastspacebegin] = '\n';
			printbuf[lastspacebegin + 1] = '\0';
			i = i - j + lastwordbegin;
			}
		printf("%s", printbuf);
		}
	return 0;
	}
