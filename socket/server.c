// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main( int arg, char *argv[]){
    int port;
    int server_fd, new_socket_fd;
    char buff[BUFFER_SIZE];
    struct sockaddr_in address;
    char senbuff[BUFFER_SIZE];
    char recbuff[BUFFER_SIZE];
    if(arg !=2){
        printf("error port \n");
        exit(EXIT_FAILURE);
    }
    port = atoi(argv[1]);
    server_fd = socket(AF_INET, SOCK_STREAM,0);
    address.sin_family = server_fd;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_fd, (struct sokkaddr *)&address, sizeof(address))==-1){
        printf("create adrress scoket error \n");
        exit(EXIT_FAILURE);
    }
    if(listen(server_fd,3) <0){
        printf("listen error \n");
        exit(EXIT_FAILURE);
    }
    while(1){
        printf("listen to port %d \n", port);
        new_socket_fd = accept(server_fd,(struct sokaddr *)&address,sizeof(address));
        if(new_socket_fd <0){
            printf("error\n");
            exit(EXIT_FAILURE);
        }
        read(new_socket_fd,recbuff, sizeof(recbuff));
        printf("buff receive :%s \n", recbuff);
        char *reponse = "hello client\n";
        write(new_socket_fd,reponse, sizeof(reponse));
        printf("input message send: ");
        fgets(senbuff, BUFFER_SIZE,stdin);
        write(new_socket_fd, &senbuff, strlen(senbuff));
        close(new_socket_fd);
    }
    close(new_socket_fd);
    close(server_fd);
    return 0;



}