#include <stdio.h>
#include <unistd.h>

int main ()
{
	char path[1024];
	if ( getcwd(path, sizeof(path)))
		printf("current directory: %s\n",path);
	else
		perror("failed to get cwd");
}
