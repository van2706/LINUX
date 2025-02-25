#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define MSQ_NAME "/my_queue"
#define SIZE 8192
int main(){
    mqd_t mq;
    mq = mq_open(MSQ_NAME,O_RDONLY);
    if (mq == -1) {
        perror("mq_open failed");
        return 1;
    }
    char message[SIZE];
    while(1){
        memset(message,0,SIZE);
        if(mq_receive(mq,message,SIZE,NULL)==-1){
            perror("message receive failed");
        }
        else{
            printf("consumer PID : %d message receive: %s\n",getpid(),message);
        }
        sleep(1);
    }
    mq_close(mq);
    return 0;
}