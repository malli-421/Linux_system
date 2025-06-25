#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	int src = open("file_managemnt/hello.txt",O_WRONLY,0644);
	int des = open("file_managemnt/text_file/hello.txt",O_RDONLY|O_TRUNC,0644);

	if ( src < 0 || des < 0 )
	{
		perror("failed to open");
		return 1;
	}
	else
	{
		char buf[1080];
		size_t bytes;
		while(( bytes = read(src,buf,sizeof(buf))) > 0 )
		{
			if ( write(des,buf,bytes) != bytes )
			{
				perror("Failed to write\n");
				close(src);
				close(des);
				return 1;
			}
		}

		if ( bytes < 0 )
			perror("read error");
		else
			printf("filed coiped successufully\n");
	}
	close(src);
	close(des);
	/*
	if ( (move(src,des)) > 0 )
	{
		printf("file coiped successfully\n");
		return 1;
	}
	*/
}
