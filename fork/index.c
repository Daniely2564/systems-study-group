#include <sys.types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    // pid_t is integer type that is specifically set up for fork
    // fork returns 0 if child,
    // returns 0 > if parents
    // returns 0 < if error.

    pid_t child = fork();

    // at the error case
    if (child < 0)
    {
        perror("fork() error"); // if there is an error we want to use perror instead of printf("").
        exit(-1);
    }

    if (child != 0)
    {
        // meaning it is current the parent process.
        printf("I'm the parent (PID = %d), and have a child (PID = %d) \n", getpid(), child);
        wait(NULL); // IMPROTANT! : Wait only waits for one child process. If there are many then, we have to wait the same number of child processes.
    }
    else
    {
        printf("I'm the child (PID = %d) and have the parent (PPID = %d)\n", getpid(), getppid());
        execl("/bin/echo", "echo", "This is how you use exec", NULL);
        // execl allows you to execute stuff.
    }
    return 0;
}