#include <stdio.h>
#include <sys/stat.h>

int main() {
    if (chmod("file.txt", 0444) == 0)
        printf("Permissions changed to read-only for 'file.txt'\n");
    else
        perror("chmod");

    return 0;
}

