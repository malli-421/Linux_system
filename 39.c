#include <stdio.h>

int main() {
    FILE *file = fopen("binary.bin", "rb");
    if (!file) {
        perror("fopen");
        return 1;
    }

    unsigned char buffer[16];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            printf("%02x ", buffer[i]);
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}

