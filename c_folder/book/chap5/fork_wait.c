#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork(); // In parent process, fork returns the child's pid. In child process, fork returns 0.
    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        exit(404); // Simulate some error.
    } else { // parent goes down this path (main)
        int exit_status; // exit status will be 0 if child process exits normally.
        int wc = wait(&exit_status);
        printf("hello, I am parent of %d (wc:%d) (pid:%d) (child exit status:%d)\n",
        rc, wc, (int) getpid(), WEXITSTATUS(exit_status));
    }
    return 0;
}

/*
COMMENTS:
rc is short for return code. It is the return value of fork() system call.
wc is short for wait code. It is the return value of wait() system call.

*/
