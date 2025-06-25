#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    char line[1024], *search = "target"; // Replace "target" with your search string
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        if (strstr(line, search)) {
            printf("String found on line %d\n", line_number);
        }
    }

    fclose(file);
    return 0;
}

