#include <stdio.h>         // printf()
#include <unistd.h>        // getpid()
#include <sys/syscall.h>   // SYS_getpid
#include <sys/types.h>     // pid_t

int main()
{
    pid_t pid1 = getpid();
    pid_t pid2 = (pid_t)syscall(SYS_getpid);

    if (pid1 == pid2)
    {
        printf("equal: %d\n", (int)pid1);
        return 0;
    }
    else
    {
        fprintf(stderr, "mismatch: %d vs %d\n", (int)pid1, (int)pid2);
        return 1;
    }
}
