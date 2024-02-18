#include <unistd.h>
#include <stdio.h>

int main(void) {

    printf("\nThis program will be replaced by ls -1 using execlp()\n");

    char *programName = "ls"; //Absolute path not required
    char *arg1 = "-1";

    execlp(programName, programName, arg1, NULL);

    printf("\nThe program successfully completed\n");

    return 0;
}
