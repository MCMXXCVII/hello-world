/*-std="c90"*/
#include <stdio.h>
#define EOL '\n'
int main()
	{
	char c, d;
	int f = 0, nc = 0, ns = 0;
	d = 1 + (c = '\n'); /*operator priority check*/
	printf("\\n = %d\n", c);
	while ((c = getchar()) != EOL) /* what if ? variable declaration in cycle condition operator*/
		{
		++nc;
		if (c == ' ')
			{
			++ns;
			++f;
			if (f > 1)
				putchar('\b');
			}
		else 
			f = 0;
		putchar(c);
		}
	printf("\nLine length is %d, quantity of spaces is %d", nc, ns);
	putchar(10);
	return 0;
	}
