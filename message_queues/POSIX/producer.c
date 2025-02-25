#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <unistd.h>

#define MSQ_NAME "/my_queue"
#define SIZE 8192
int main(){
    struct mq_attr attr;
    mqd_t mq;
    char message[SIZE];
    attr.mq_flags = 0; // 0= blocking mode
    attr.mq_msgsize =10;
    attr.mq_maxmsg =SIZE;
    attr.mq_curmsgs =0;
    mq = mq_open(MSQ_NAME,O_CREAT|O_WRONLY, 0644, 0);
    if(mq ==-1){
        perror("mq failed");
        return -1;
    }

    int count =1;
    while(1){
        snprintf(message,SIZE,"chuoi : %d",count++);
        if(mq_send(mq,message, strlen(message)+1,0)==-1){
           perror("msg_send failed");
        }
        else{
            printf("message : %s\n",message);
        }
        sleep(2);
    }
    mq_close(mq);
    return 0;


}