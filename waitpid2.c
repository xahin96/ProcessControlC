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
        int grandchild_pid = pid2 == 0 ? getpid() : pid2; // Get the process ID of the grandchild process
        int child_pid = waitpid(grandchild_pid, &status, 0); // Waiting for the grandchild process
        printf("The main process resumed execution and was waiting for : %d\n", child_pid);
    }
    if (pid1 == 0 && pid2 > 0) {
        printf("First child: %d %d\n", getpid(), getppid());
        for (int i = 0; i < 5; i++) {
            sleep(1);
            printf("First child: %d %d\n", getpid(), getppid());
        }
    }
    if (pid1 > 0 && pid2 == 0) {
        printf("Second child: %d %d\n", getpid(), getppid());
    }
    if (pid1 == 0 && pid2 == 0) {
        printf("Grandchild Process:%d %d\n", getpid(), getppid());
    }
}
