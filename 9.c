#include <stdio.h>
#include <dirent.h>

int main ()
{
	DIR *dir;

	struct dirent *entry;
	
	dir = opendir(".");
	if ( dir < 0 )
	{
		perror("failed to open");
		return 1;
	}

	while ((entry = readdir(dir)) != NULL )
	{
		printf("%s\n",entry->d_name);
	}
	closedir(dir);
}




