#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	DIR *dir;

	struct dirent *entry;

	dir = opendir("TEST");
	if ( dir == NULL )
	{
		perror("dirctory is not present\n");
		return 1;
	}
	else
		printf("dirctory is present\n");

}
