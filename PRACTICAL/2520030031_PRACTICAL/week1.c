#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    char cmd[10];
    pid_t pid;

    printf("Enter the command: ");
    scanf("%s", cmd);

    pid = fork();

    if(pid == 0)
    {
        printf("Child PID: %d\n", getpid());

        execlp(cmd, cmd, NULL);

        printf("exec() system call failed\n");
        exit(1);
    }
    else
    {
        wait(NULL);

        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}
