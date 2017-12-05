/*-std="c90"*/
#include <stdio.h>
#define MIN 140
#define MAX -40
#define STEP 10
int main()
	{
	printf ("Celsius | Fahrentheit\n");
	for (int cels = MIN; cels >= MAX; cels = cels - STEP)
		printf ("%7d | %.0f\n", cels, cels * 9.0 / 5.0 + 32.0);
	return 0;
	}
