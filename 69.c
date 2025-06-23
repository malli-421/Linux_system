#include <stdio.h>

int main() {
    FILE *file = fopen("notes.txt", "w");
    if (!file) {
        perror("fopen");
        return 1;
    }

    fprintf(file, "Line 1: Welcome to the notes.\n");
    fprintf(file, "Line 2: This is a second line.\n");
    fprintf(file, "Line 3: End of notes.\n");

    fclose(file);
    printf("Multiple lines written to 'notes.txt'\n");
    return 0;
}

