#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat st;

    if (stat("hello.txt", &st) == -1) {
        perror("stat");
        return 1;
    }

    printf("Permissions: %o\n", st.st_mode & 0777); // Show permissions in octal format

    return 0;
}

