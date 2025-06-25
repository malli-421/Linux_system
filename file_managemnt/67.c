#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *tmp = tmpfile();
    if (!tmp) {
        perror("tmpfile");
        return 1;
    }

    fprintf(tmp, "This is temporary data.\n");
    rewind(tmp);

    char buffer[100];
    fgets(buffer, sizeof(buffer), tmp);
    printf("Data in temp file: %s", buffer);

    fclose(tmp); // Automatically deleted when closed
    return 0;
}

