#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[256];
    int fd = open("myfifo", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);
    if (n >= 0) {
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(fd);
    return 0;
}

