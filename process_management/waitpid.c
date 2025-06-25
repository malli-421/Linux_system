#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main ()
{
	pid_t pid = fork();
	if(pid<0)
		perror("failed fork");
	else if(pid==0)
		printf("child process terminated\n");
	else
	{
		int stat;
		waitpid(pid,&stat,0);
		if(WIFEXITED(stat))
			printf("parent is waiting for child termination: %d\n",WEXITSTATUS(stat));
		else 
			printf("child did not terminate normally\n");
		printf("parent execution completed\n");
	}
}

