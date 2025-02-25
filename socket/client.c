// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
int main( int arg, char *argv[]){
int port;
char *ip = argv[1];
struct sockaddr_in address;
int buff[BUFFER_SIZE];
int socke;
char senbuff[BUFFER_SIZE];
char recbuff[BUFFER_SIZE];
int num_read;
if(arg !=3){
    printf("input ip and port error\n");
    exit(EXIT_FAILURE);
}
port = atoi(argv[2]);
if(socke = socket(AF_INET, SOCK_STREAM,0)<0){
    printf("create socket error\n");
    exit(EXIT_FAILURE);
}
address.sin_family = socke;
address.sin_port = htons(port);
if(inet_pton(AF_INET, ip, &address.sin_addr.s_addr)==-1){
    printf("error convert binary ip\n");
    exit (EXIT_FAILURE);
}
if(connect(socke, (struct sockaddr *)&address, sizeof(address))==-1){
    printf("error  connect\n");
    exit(EXIT_FAILURE);
}
while(1){
    memset(recbuff, 0, BUFFER_SIZE);
    memset(senbuff,0, BUFFER_SIZE);
    num_read = read(socke,&recbuff, strlen(recbuff));
    if(num_read ==-1){
        printf("error receiver message\n");
    }
    printf("input message send: ");
    fgets(senbuff, BUFFER_SIZE,stdin);
    write(socke, &senbuff, strlen(senbuff));
}

close(socke);

}