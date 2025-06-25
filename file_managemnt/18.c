#include <stdio.h>
#include <unistd.h>

int main ()
{
	const char *filename = "hai.txt";

	if ( chown(filename,1001,-1) != 0 )
	{
		perror("failed to change owner");
		return 1;
	}
	else
		printf("Owner ship was changed successfully\n");

}
