#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid_child;
    int status, rm;

    pid_child = fork();
    if(pid_child >=0){
        if(pid_child ==0){
            printf("xin chao \n");
            printf("my pid child : %d\n", getpid());
            //while(1);
           sleep(10);
           //exit(status);
        }
        else{
            printf("my pid parent : %d, my pid child :%d\n", getpid(), pid_child);
           rm =  wait(&status);
           if(rm ==-1){
            printf("exit unsecces\n");
           }else{
            printf("process end with pid child :%d\n", rm);
           }
        }
    }
    else {
        printf("error pid child\n");
    }
    return 0;
}