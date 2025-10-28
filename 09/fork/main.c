
#include <unistd.h>    // fork() execlp()
#include <sys/wait.h>  // wait()
#include <stdio.h>     // perror()

int main()
{
    pid_t pid = fork();  // subprocess

    if (pid == -1)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        execlp("expr", "expr", "2", "+", "2", "*", "2", NULL); // run expr
        perror("execlp");  // if not execlp
        return 1;
    }

    wait(NULL); // wait subprocess
    printf("success");
    return 0;
}
