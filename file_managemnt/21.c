#include <stdio.h>
#include <sys/stat.h>

int main ( int argc, char *arg[] )
{
	struct stat path_stat;
	if ( argc < 2 )
	{
		printf("Usage: %s <path>\n",arg[0]);
		return 1;
	}
	stat( arg[1], &path_stat );
	if ( S_ISDIR( path_stat.st_mode) )
		printf("Directory\n");
	else if ( S_ISREG(path_stat.st_mode) )
		printf("file\n");
	else
		printf("others\n");
}
