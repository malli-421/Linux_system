#include <stdio.h>

int main() {
    FILE *file = fopen("log.txt", "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    int lines = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n')
            lines++;
    }

    fclose(file);
    printf("Total lines in 'log.txt': %d\n", lines);
    return 0;
}

