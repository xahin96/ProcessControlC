#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
    int p = fork();

    if (p == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (p == 0) {
        printf("\nWe are in the child process\n");
        printf("\nThe child process is now being replaced by another executable using execl");
        int i = execl("/Users/zahin/My Files/uWindsor/Sem 2/COMP 8567/Assignment 2/Code2/fileutil",
                      "fileutil",
                      "/Users/zahin/My Files/test/task 1 copy 30",
                      "a1.c",
                      NULL);
//        int i = execlp("/Users/zahin/My Files/uWindsor/Sem 2/COMP 8567/Assignment 2/Code2/fileutil",
//                       "fileutil",
//                       "/Users/zahin/My Files/test/task 1 copy 30/folder2",
//                       "/Users/zahin/My Files/test/task 1 copy 30/folder1",
//                       "-cp",
//                       "a1.c",
//                       NULL);
        if (i == -1) {
            perror("execl");
            exit(EXIT_FAILURE);
        }
        printf("\nWe are in the child process\n");
        exit(EXIT_SUCCESS);
    } else {
        int status;
        int k = wait(&status);
        if (k == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
        printf("\nWe are in the parent process\n");
        exit(EXIT_SUCCESS);
    }
    return 0;
}
