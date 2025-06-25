#include <stdio.h>
#include <unistd.h>

int main() {
    if (access("file.txt", F_OK) == 0)
        printf("File 'file.txt' exists.\n");
    else
        printf("File 'file.txt' does not exist.\n");

    return 0;
}

