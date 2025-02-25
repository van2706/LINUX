#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
int main(int agr, char *agrv[]){
    int sock_fd;
    struct sockaddr_in server_add;
    char *ip = agrv[1];
    char buffer[BUFFER_SIZE];
    int port;
    
    if(agr!=3){
        printf("input init error \n");
        exit(EXIT_FAILURE);
    }
    sock_fd = socket(AF_INET, SOCK_STREAM,0);
    if(sock_fd ==-1){
        printf("create error\n");
        exit(EXIT_FAILURE);
    }
    port = atoi(agrv[2]);
    server_add.sin_family = AF_INET;
    server_add.sin_port = htons(port);
    if(inet_pton(AF_INET, ip,&server_add.sin_addr)<=0){
        perror("Invalid IP address");
        printf("error convert binary\n");
        exit(EXIT_FAILURE);
    }
    if(connect(sock_fd, (struct sockaddr *)&server_add, sizeof(server_add))==-1){
        perror("Connect error");
        printf("connet error \n");
        exit(EXIT_FAILURE);
    }
    char *message = "xin chao message duoc gui tu client";
    write(sock_fd,message,strlen(message));
    printf("da gui tin tu client\n");
    
    memset(buffer, 0, BUFFER_SIZE);
    read(sock_fd, buffer, BUFFER_SIZE);
    printf("buffer recive : %s", buffer);


}