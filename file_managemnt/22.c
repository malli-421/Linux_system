#include <stdio.h>
#include <unistd.h>

int main ()
{
	if ( link("Message.txt", "hardlink.txt") == 0 )
		printf("Hard link created successfully\n");
	else
		perror("Link");
}

