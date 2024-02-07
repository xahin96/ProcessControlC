#include <unistd.h>
#include <stdio.h>
 
int main(void) {

  printf("\nThe program will be replaced by 'ls -1 /home/pranga/chapter3'  using execv()\n"); 
  
  char *programName = "/bin/ls";
  char *args[] = {"/bin/ls",NULL};
  //Note: ls has two arguments in this example
 
  execv(programName, args);
  
  printf("\nThe program successfully completed\n"); 
  return 0;
}
