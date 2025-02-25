#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SERVER_FIFO "./server_fifo"
#define BUFF_SIZE 1024
int main(int arg, char argv[]){
    char buff[BUFF_SIZE];
    int server_fd, client_fd;
    char client_FIFO[100];
    sprintf(client_FIFO, "./client_fifo_%d",getpid());
    printf("client fifo: %s\n", client_FIFO);
    //  Mo server
    server_fd =open(SERVER_FIFO, O_WRONLY);
    if(server_fd==-1){
        printf("open server error\n");
        exit(EXIT_FAILURE);
    }
    char key[100]="KEY_VALUE";
    char service_request[100]= "xin_chao";
    sprintf(buff,"%s %s %s", client_FIFO, service_request, key);
    write(server_fd, buff, strlen(buff)+1);
     // Mo client, Nhận phản hồi từ server
     mkfifo(client_FIFO, 0666);
     memset(buff,0, BUFF_SIZE);
    client_fd = open(client_FIFO, O_RDONLY);
    if(client_fd ==-1){
        printf("open client error\n");
        exit(EXIT_FAILURE);
    }
    read(client_fd, buff, BUFF_SIZE);
    printf("buff received :%s\n",buff);
    if(strcmp(buff,"accept")==0){
        printf("connection accepted by server\n");
    }
    else{
        printf("connection rejected by server\n");
    }
    close(client_fd);
    close(server_fd);
    return 0;
}