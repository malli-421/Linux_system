#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in = fopen("Message.txt", "r");
    FILE *out = fopen("output.txt", "w");

    if (!in || !out) {
        perror("File open");
        return 1;
    }

    fseek(in, 0, SEEK_END);
    long size = ftell(in);

    for (long i = size - 1; i >= 0; i--) {
        fseek(in, i, SEEK_SET);
        int ch = fgetc(in);
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);
    printf("Reversed content written to output.txt\n");

    return 0;
}

