

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

//Termination status of the child process using macros defined in sys/wait.h
//WIFEXITED(),WIFSIGNALED(),WEXITSTATUS(),WTERMSIG()

int main() {
    int i, num = 1;
    int pid = fork();
    if (pid == 0) {
        num = num / 0;
        for (int i = 0; i < 3; i++) {
            sleep(1);
            int c = 100 / 0;
            printf("c = %d", c);
            printf("\nFrom the child process: PID = %d\n", getpid());
            printf("\nFrom the child process: PPID = %d\n", getppid());
        }
        exit(48);
    } else if (pid < 0) {
        //error
    } else {
        int status;
        int k = wait(&status);
        printf("\nThe parent process has resumed execution %d\n", status);
        if (WIFEXITED(status)) {
            printf("Normal Exit: %d \n", WEXITSTATUS(status));
        } else  //WIFSIGNALED(status) is true
        {
            printf("Signalled Exit: %d\n", WTERMSIG(status));
        }
    }
}
