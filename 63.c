#include <stdio.h>
#include <unistd.h>

int main() {
    if (symlink("target.txt", "link.txt") == 0)
        printf("Symbolic link 'link.txt' created for 'target.txt'\n");
    else
        perror("symlink");

    return 0;
}

