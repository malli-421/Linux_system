#include <stdio.h>
#include <sys/stat.h>

int main ()
{
	if( chmod("Message.txt",0444) == -1 )
	{
		perror("chmod failed");
		return 1;
	}
	else
		printf("permissions changes succssfully\n");
}
