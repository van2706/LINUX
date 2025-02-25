#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define BUFFER_SIZE 1024

struct mesg_buffer{
    long mesg_type;
    char message_text[BUFFER_SIZE];
}message;
int main(){

    int msgid;
    key_t key = ftok("progfile",50);
    msgid = msgget(key,IPC_CREAT|0666);
    // receive message
    msgrcv(msgid,&message,sizeof(message),1,0);
    printf("Data receive: %s\n", message.message_text);
    return 0;
}