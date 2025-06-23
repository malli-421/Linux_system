#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    mkdir("Logs", 0755);
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".log")) {
            char dest[512];
            snprintf(dest, sizeof(dest), "Logs/%s", entry->d_name);
            if (rename(entry->d_name, dest) != 0) {
                perror("rename");
            } else {
                printf("Moved %s to Logs/\n", entry->d_name);
            }
        }
    }

    closedir(dir);
    return 0;
}

