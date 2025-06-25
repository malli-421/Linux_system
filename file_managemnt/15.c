#include <stdio.h>

void  main ()
{
	FILE *file = fopen("12.c","r");
	
	if ( file < 0 )
	{
		perror("failed to open file");
		return;
	}
	int lines = 0;
	char ch;
	while (( ch = fgetc(file)) != EOF )
	{
		if ( ch == '\n' )
			lines++;
	}
	fclose(file);
	printf("Number of lines: %d\n",lines);
}
