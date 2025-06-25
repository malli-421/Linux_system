#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    DIR *dir = opendir("TEST");
    struct dirent *entry;
    struct stat st;
    int count = 0;
    char path[512];

    if (!dir) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        snprintf(path, sizeof(path), "Images/%s", entry->d_name);
        if (stat(path, &st) == 0 && S_ISREG(st.st_mode))
            count++;
    }

    closedir(dir);
    printf("Number of files in 'Images': %d\n", count);
    return 0;
}

