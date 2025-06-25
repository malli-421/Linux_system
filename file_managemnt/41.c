#include <stdio.h>
#include <unistd.h>

int main() {
    if (access("data.txt", R_OK) == 0)
        printf("File 'data.txt' is readable.\n");
    else
        perror("File 'data.txt' is not readable");

    return 0;
}

