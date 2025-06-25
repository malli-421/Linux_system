#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) 
    {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) 
    {
        
        printf("Child process: PID = %d\n", getpid());
        exit(0);
    } 
    else 
    {
        printf("Parent process: PID = %d\n", getpid());
        printf("Child created, but not waited on... creating zombie 🧟\n");
        sleep(30);  // Gives you time to observe 'ps' output
    }

    return 0;
}

