#include <stdio.h>

int main() {
    FILE *fp = fopen("empty.txt", "w");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    fclose(fp);
    printf("File 'empty.txt' created successfully.\n");
    return 0;
}

