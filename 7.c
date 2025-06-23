#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main ()
{
	int src = open("hello.txt",O_RDONLY,0666);
	int des = open("hai.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);

	if ( src < 0 || des < 0 )
	{
		perror("failed to open\n");
		return 1;
	}
	else
	{
	char buf[100];
	int bytes;
        while( (bytes = read(src,buf,sizeof(buf))) > 0 )
	{
		write(des,buf,bytes);
	}
	close(src);
	close(des);
	}

}
