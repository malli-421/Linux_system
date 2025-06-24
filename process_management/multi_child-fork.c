#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	pid_t pid = fork();
	if ( pid < 0 )
		perror("PID accured error");
	for( int i = 0 ; i < 5 ; i++ )
	{
		if ( pid == 0 )
			printf("child %d: if PID is: %d\n",i+1,getpid());
		else
			printf("parent process\n");
	}
}
