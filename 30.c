#include <stdio.h>
#include <unistd.h>

int main() {
    const char *filename = "hello.txt";
    off_t length = 10;

    if (truncate(filename, length) == -1) {
        perror("truncate");
        return 1;
    }

    printf("File '%s' truncated to %ld bytes.\n", filename, (long)length);
    return 0;
}

