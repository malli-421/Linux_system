#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main ()
{
	pid_t pid = vfork();
	if( pid < 0 )
		perror("failed VFORK");
	else if( pid == 0 )
	{
		char *arg[] = { "ls","-l",NULL};
		printf("Example of EXECVP() syatem call\n");
		execvp(arg[0],arg);
		printf("this will never appers\n");
		perror("execvp failed");
		_exit(1);
	}
	else
	{
		printf("parent- CHILD PI: %d\n",pid);
		wait(NULL);
	}
}
