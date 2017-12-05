/*-Wall -std=c90 -o=40.out*/
/* FILE *fps;
   fps = fopen("filepath", "r|a|w|r+|a+|w+");
   {}
   fclose(fps);
 * r a w r+ a+ w+
 * char fgetc(fps);
 * fputc(c, fps);
 * fscanf(fps, "format line", args);
 * fprintf(fps, "format line", args);
 * fgets(s, lim, fps);
 * fputs(s, fps);
 * fflush(fps);
 */

/*? how to compile complex projects of several files*/

#include <stdio.h>
#define LIM 40

int fgetline(fps, s, lim)
FILE *fps;
char s[];
int lim;
{
	int i, c;
	for (i = 0; !(i >= lim - 1 || (c = fgetc(fps)) == '\n' || c == EOF); ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return (i);
}

int index(s, t)
char s[], t[];
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; ++j, ++k);
		if (t[k] == '\0')
			return (i);
	}
	return (-1);
}

int main() {
	FILE *fps;
	fps = fopen("40.txt", "r");
	int len = 0;
	char s[LIM + 1] = "",
	t[] = "the";
	while ((len = fgetline(fps, s, LIM)) > 0)
		if (index(s, t) >= 0)
			printf("%s", s);
	fclose(fps);
	
	 FILE *file;
    char c;
 
    file = fopen("test.txt", "w+");
     
    do {
        c = getchar();
        fprintf(file, "%c", c);
        fprintf(stdout, "%c", c);
        /*fflush(file);*/
    } while(c != 'q');
 
    fclose(file);
    getchar();
	return 0;
}
