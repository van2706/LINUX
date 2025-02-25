#include  <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int agr, char *agrv[]){
    int server_fd, client_fd;
    socklen_t len;
    struct sockaddr_in address_server, address_client;
    int port;
    char redata[BUFFER_SIZE], sedata[BUFFER_SIZE];
    if(agr != 2){
    printf("input init error\n");
    exit(EXIT_FAILURE);
    }
    port = atoi(agrv[1]);
    server_fd = socket(AF_INET, SOCK_STREAM,0);
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if(server_fd==-1){
        printf("create server fd error\n");
        exit(EXIT_FAILURE);
    }
    address_server.sin_family = AF_INET;
    address_server.sin_port = htons(port);
    address_server.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_fd, (struct sockaddr *)&address_server, sizeof(address_server))==-1){
        printf("bind error\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    if(listen (server_fd, 5)==-1){
        printf("listen error\n");
        exit(EXIT_FAILURE);
    }
    while(1){
        len = sizeof(address_client);
        client_fd = accept(server_fd, (struct sockaddr *)&address_client, &len);
        printf("Client connected from %s:%d\n", inet_ntoa(address_client.sin_addr), ntohs(address_client.sin_port));
        if(client_fd==-1){
            printf("create client fd error\n");
            exit(EXIT_FAILURE);
        }
        memset (redata, 0, BUFFER_SIZE);
        int byte = read(client_fd, redata, BUFFER_SIZE);
        if(byte <0){
            printf("error read\n");
        }
        else if (byte == 0) {
            printf("Client disconnected\n");
        }
        else {
            printf("buffer server read : %s\n", redata);
        }
        // ghi du lieu vao client
        char *message ="xin chao client toi den tu server";
        write(client_fd, message,strlen(message) );
        close (client_fd);
    }
    //close (client_fd);
    close(server_fd);

    return 0;
}