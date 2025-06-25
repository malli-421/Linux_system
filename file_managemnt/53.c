#include <stdio.h>

int main() {
    FILE *file = fopen("output.txt", "w");
    if (!file) {
        perror("fopen");
        return 1;
    }

    fprintf(file, "Hello, World!\n");
    fclose(file);

    printf("Message written to 'output.txt'\n");
    return 0;
}

