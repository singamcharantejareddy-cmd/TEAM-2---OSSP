#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

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

        sleep(20);

        printf("Parent terminating...\n");
    }

    return 0;
}
