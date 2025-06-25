#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    FILE *out = fopen("combined.txt", "w");
    if (!out) {
        perror("fopen combined.txt");
        closedir(dir);
        return 1;
    }

    struct dirent *entry;
    char buffer[1024];

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".txt") && strcmp(entry->d_name, "combined.txt") != 0) {
            FILE *in = fopen(entry->d_name, "r");
            if (in) {
                while (fgets(buffer, sizeof(buffer), in)) {
                    fputs(buffer, out);
                }
                fclose(in);
                printf("Added: %s\n", entry->d_name);
            }
        }
    }

    fclose(out);
    closedir(dir);
    return 0;
}

