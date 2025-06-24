#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	int pid = fork();
	if ( pid == 0 )
	{
		printf("CHILD process\n");
	}
	else if ( pid > 1 )
	{
		printf("PARENT process\n");
	}
	else
		perror("FORK failed\n");
}
