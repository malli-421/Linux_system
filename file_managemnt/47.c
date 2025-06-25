#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

long long get_total_size(const char *path) {
    struct stat st;
    long long total = 0;

    DIR *dir = opendir(path);
    if (!dir) return 0;

    struct dirent *entry;
    char fullpath[1024];

    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        if (lstat(fullpath, &st) == -1) continue;

        if (S_ISDIR(st.st_mode)) {
            total += get_total_size(fullpath);
        } else if (S_ISREG(st.st_mode)) {
            total += st.st_size;
        }
    }

    closedir(dir);
    return total;
}

int main() {
    const char *path = ".";  // current directory
    long long size = get_total_size(path);
    printf("Total size of all files: %lld bytes\n", size);
    return 0;
}

