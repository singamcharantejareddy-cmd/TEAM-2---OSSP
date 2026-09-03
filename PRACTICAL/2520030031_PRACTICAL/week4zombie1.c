#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child process terminating...\n");
        exit(0);
    }
    else {
        printf("Parent PID: %d\n", getpid());
        printf("Child PID : %d\n", pid);

        wait(NULL);

        printf("Child process collected by parent.\n");
    }

    return 0;
}
