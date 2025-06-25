#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main ()
{
	int fd = open("Message.txt",O_RDONLY);
	if ( fd < 0 )
	{
		perror("failed to open");
		return 1;
	}
	else
	{
		struct stat buf;

		if( fstat(fd,&buf) < 0 )
		{
			perror("stat failed");
		       return 1;
		}
 		else
			printf("file time: %s\n",ctime(&buf.st_mtime));
	}
	close(fd);	
}
