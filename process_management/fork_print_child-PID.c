#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main ()
{
	pid_t pid = fork();
	if( pid < 0 )
		perror("failed fork()\n");
	else if ( pid == 0 )
		printf("child process: %d\n",getpid());
	else
		printf("parent proces\n");
}
