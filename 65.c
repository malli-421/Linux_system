#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    struct passwd *pw = getpwnam("user1");
    if (!pw) {
        perror("getpwnam");
        return 1;
    }

    if (chown("file.txt", pw->pw_uid, pw->pw_gid) == 0)
        printf("Ownership of 'file.txt' changed to user1\n");
    else
        perror("chown");

    return 0;
}

