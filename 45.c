#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat st;

    if (stat("Message.txt", &st) == -1) {
        perror("stat");
        return 1;
    }

    printf("Number of hard links to 'file.txt': %lu\n", st.st_nlink);
    return 0;
}

