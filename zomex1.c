#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]){
int pid;
pid = fork();

if(pid==0)
{
//Child
int num=10/0;
printf("child process, pid=%d\n", getpid());
exit(0);
}
else if(pid<0)
{
printf("Error Forking"); 
}
else
{
//Parent
printf("Parent process, pid=%d\n", getpid());
while(1)
{}
}


}
