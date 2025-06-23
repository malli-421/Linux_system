#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main ()
{
	int ret;
	int fd = open("Message.txt",O_WRONLY|O_APPEND|O_CREAT, 0644);
	char buf[10];
	if ( fd < 0 )
	{
		perror("failed to open");
		return;
	}
	else
	{
		char *text = "Goodbye!";
		ret = write(fd,text,sizeof(text));
			buf[ret] = '\0';
			printf("NO.of Bytes are written %d in to 'Message.txt'\n",ret);
		
	}
	close(fd);
}

