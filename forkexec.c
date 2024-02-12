#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int p;
    p = fork();

    if (p == -1) {
        printf("There is an error while calling fork()");
    }
    if (p == 0) {
        printf("\nWe are in the child process\n");
        printf("\nThe child process is now being replaced by another executable using execl");
        int i = execl("/bin/ls", "bin/ls", "-1", NULL);
//        int i = execl("xyz100", "xyz100", "-1", NULL);

        printf("\nWe are in the child process\n");
        exit(0);
    } else {
        int k = wait(0);
        printf("\nWe are in the parent process\n");
        exit(0);
    }
    return 0;
}
