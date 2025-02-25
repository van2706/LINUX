#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handle(int num){
    printf("\nin handle signal :%d\n",num);
    exit(EXIT_SUCCESS);
}
int main(){
    if(signal(SIGINT, signal_handle) == SIG_ERR){
        printf("error");
        exit(EXIT_FAILURE);
    }
    printf("PID process: %d\n", getpid());
    while(1){
        printf("hello\n");
        sleep(1);
    }
    return 0;

}