#include <stdio.h>
#include <stdlib.h>

int main ()
{
	FILE *file = fopen("data.csv", "r");
	char buffer[1024];

	if( !file )
	{
		perror("fopen");
		return 1;
	}

	while ( fgets(buffer,sizeof(buffer), file) )
	{
		printf("%s",buffer);
	}
	fclose(file);
}
