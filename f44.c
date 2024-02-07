#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int a;
    a = fork();
    if (a != 0) {
        sleep(10);
    }
    a = fork();
    if (a != 0) {
        sleep(10);
    }
    a = fork();
    if (a != 0) {
        sleep(10);
    }
    a = fork();
    if (a != 0) {
        sleep(10);
    }

    printf("\nProcess id = %d, Parent id= %d\n", getpid(), getppid());
} 

