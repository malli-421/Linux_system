#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
    return 0;
}

