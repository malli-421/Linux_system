#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main ()
{
	DIR *dir;

	struct dirent *entry;

	dir = opendir("Backup");
	if ( dir == NULL )
	{
		if ( mkdir("Backup",0644) != 0 )
		{	
		perror("dirctory is not present\n");
		return 1;
		}
		printf("dirctory 'Backup' is created successfully\n");
		dir = opendir("Backup");
	}
	else
	{
		printf("dirctory 'Backup' is not created successfully\n");
	}
	while (( entry = readdir(dir)) > 0)
	{
		printf("%s\n",entry->d_name);
	}
	closedir(dir);
}
