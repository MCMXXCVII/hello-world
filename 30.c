/* -std="c89" */ 
#include <stdio.h>
#define LIM 25

int initchararr(v, lim)
char v[];
int lim;
{
	int i;
	for (i = 0; i < lim; ++i)
		v[i] = i + '0';
	return 0;
}

int printchararr(s, lim)
char s[];
int lim;
{
	int i;
	for (i = 0; i < lim; ++i)
		putchar(s[i]);
	return 0;
}

int bindivchararr(v, x, lim)
char v[], x, lim; /* char a[] vs. unsigned short int a[] */
{
	int low, hig, mid;
	low = 0;
	hig = lim - 1;
	while (low <= hig) /* ? why <= because final step is low==hig*/
	{
		mid = (low + hig) / 2;
		if (x < v[mid])
			hig = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return (mid);
	}
	return (-1);
}

int countchararr(s, lim)
char s[]; 
int lim;
{
	int ndig[10], nwhi, noth, i;
	for (i = 0; i < 10; ++i)
		ndig[i] = 0;
	nwhi = noth = 0;
	for (i = 0; i < lim; ++i)
	{
		switch (s[i])
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			ndig[s[i] - '0']++;
			break;
			case ' ':
			case '\n':
			case '\t':
			nwhi++;
			break;
			default:
			noth++;
			break;
		}
	}
	printf("\ndigits =");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndig[i]);
	printf("\nwhite space = %d, other = %d\n", nwhi, noth);
	return 0;
}

int main()
{
	char v[LIM];
	int x = 0;
	initchararr(v, LIM);
	printchararr(v, LIM);
	countchararr(v, LIM);
	printf("enter a number: ");
	scanf("%d", &x);
	putchar(x);
	putchar('\n');
	if ((x = bindivchararr(v, x, LIM)) >= 0)
		printf("position: %d\n", x);
	else
		printf("position not found\n");
	
	printf("char a[] vs. unsigned short int a[]\n%lu vs. %lu\n", sizeof (char), sizeof (unsigned short int));
	
	return 0;
}
