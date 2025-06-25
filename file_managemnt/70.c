#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file = fopen("essay.txt", "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    int wordCount = 0;
    char ch, prev = ' ';

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch) && !isspace(prev)) {
            wordCount++;
        }
        prev = ch;
    }

    // Edge case: if last word doesn't end in whitespace
    if (!isspace(prev))
        wordCount++;

    fclose(file);
    printf("Word count in 'essay.txt': %d\n", wordCount);
    return 0;
}

