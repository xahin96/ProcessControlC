#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int p;
    p = fork();

    if (p == -1) {
        printf("There was an error while calling fork()");
    }
    if (p == 0) {
        for (;;) {
            printf("\nWe are in the child process %d\n", p);
            sleep(2);
        }
        exit(0);
    } else {
        for (;;) {
            printf("\nWe are in the parent process %d\n", p);
            sleep(2);
        }
        exit(0);
    }
    return 0;
}
