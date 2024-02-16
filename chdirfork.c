#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int p, p1;
    p = fork();

    if (p == -1) {
        printf("There is an error while calling fork()");
    }
    if (p == 0) {
        printf("\nWe are in the child process\n");
        char s[100];
        // current working directory
        printf("\nThe current working directory of the child process is %s\n", getcwd(s, 100));
        // using the system call chdir()
        chdir("/Users/zahin/My Files/");

        printf("\nThe new working directory of the child process is %s\n", getcwd(s, 100));
        // new working directory

        exit(0);
    } else {
        int k = wait(0);
        printf("\nParent process resumes\n");
        char *s;
        exit(0);
    }
    return 0;
}
