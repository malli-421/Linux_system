#include <stdio.h>

int main() {
    FILE *file = fopen("image.jpg", "rb");
    if (!file) {
        perror("fopen");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);

    printf("Size of 'image.jpg': %ld bytes\n", size);
    return 0;
}

