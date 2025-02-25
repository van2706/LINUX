#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define BUFFER_SIZE 1024
// struct for message
struct message_buffer{
    long mesg_type;
    char message_text[1024];
}message;

int main(){

    key_t key;
    int msgid;
    // tạo key
    key = ftok("progfile", 50);
    // tạo file descriptor
    msgid = msgget(key,IPC_CREAT|0666);
    if(msgid ==-1){
        printf("msgget error");
        return 1;
    }
    printf("Enter message type: ");
    scanf("%ld", &message.mesg_type);
    stdin = freopen(NULL,"r",stdin); // clear input buffer

    printf("Enter message: ");
    fgets(message.message_text, BUFFER_SIZE,stdin);
    // gui message
    msgsnd(msgid, &message, sizeof(message), 0);




}