#include <stdio.h>
#include <sys/stat.h>

int main ()
{
	struct stat dir_stat;
	if ( stat("TEST", &dir_stat) == 0 )
		printf("size: %lld bytes\n",(long long)dir_stat.st_size);
	else
		perror("failed stat");
}
