#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid1, pid2;

    pid1 = fork();

    if(pid1 == 0)
    {
        printf("Child 1: PID = %d\n", getpid());
        sleep(2);
        printf("Child 1 finished\n");
        return 0;
    }

    pid2 = fork();

    if(pid2 == 0)
    {
        printf("Child 2: PID = %d\n", getpid());
        sleep(4);
        printf("Child 2 finished\n");
        return 0;
    }

    printf("Parent waiting for Child 1...\n");
    waitpid(pid1, NULL, 0);

    printf("Parent waiting for Child 2...\n");
    waitpid(pid2, NULL, 0);

    printf("Both children finished\n");

    return 0;
}
