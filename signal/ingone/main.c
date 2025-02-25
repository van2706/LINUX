#define _POSIX_SOURCE
#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <signal.h>

void signal_handle(int num){
    printf("signal handle : %d\n", num);
    exit(EXIT_SUCCESS);
}
int main(){
    sigset_t new_set, old_set;
    if(signal(SIGINT, signal_handle)==SIG_ERR){
        printf("error\n");
        exit(EXIT_FAILURE);
    }
    printf("new set is:%x\n",new_set);
    sigemptyset(&new_set);
    sigemptyset(&old_set);
    sigaddset(&new_set,SIGINT);
    if(sigprocmask(SIG_SETMASK, &new_set, &old_set)==0){
        if(sigismember(&new_set,SIGINT)==1){
            printf("SIGINT exist\n");
        }
        else if(sigismember(&new_set,SIGINT)==0){
            printf("SIGINT does not exist \n");
        }
    }
    while(1){
        printf("hello\n");
        sleep(1);
    }
    return 0;
}