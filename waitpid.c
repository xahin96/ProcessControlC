#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
    int pid1, pid2;
    pid1 = fork();
    pid2 = fork();
    if (pid1 > 0 && pid2 > 0) {
        printf("Main Process will now go into wait: %d %d\n", getpid(), getppid());
        int status;
        int child_pid = waitpid(pid1, &status, 0);
        printf("The main process resumed execution and was waiting for : %d\n", child_pid);
        printf("status : %d\n", status);
        if (WIFEXITED(status)) {
            printf("WIFEXITED Exit: %d \n", WEXITSTATUS(status));
            printf("WIFSIGNALED Exit: %d \n", WIFSIGNALED(status));
        } else {
            printf("WIFSIGNALED Exit: %d \n", WIFSIGNALED(status));
            printf("WTERMSIG Exit: %d \n", WTERMSIG(status));
        }
    }
    if (pid1 == 0 && pid2 > 0) {
        printf("First child: %d %d\n", getpid(), getppid());
//        int ii = 1 / 0;
        for (int i = 0; i < 5; i++) {
            sleep(1);
            printf("First child: %d %d\n", getpid(), getppid());
        }
//        exit(50);
    }
    if (pid1 > 0 && pid2 == 0) {
        printf("Second child: %d %d\n", getpid(), getppid());
    }
    if (pid1 == 0 && pid2 == 0) {
        printf("Grandchild Process:%d %d\n", getpid(), getppid());
    }
}
