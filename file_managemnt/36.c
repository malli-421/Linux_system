#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    char line[1024];
    int count = 0;

    while (fgets(line, sizeof(line), file) && count < 10) {
        printf("%s", line);
        count++;
    }

    fclose(file);
    return 0;
}

