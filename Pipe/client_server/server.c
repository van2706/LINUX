#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#define SERVER_FIFO "./server_fifo"
#define COUNT_MAX 3
#define BUFF_SIZE 1024
int cout_connection =0;
int main(int arg, char *agrv){
    
    char buff[BUFF_SIZE];
    int server_fd, client_fd, st_read;
    if(mkfifo(SERVER_FIFO, 0666)==-1){
        printf("Error create fifo \n");
        exit(EXIT_FAILURE);
    }
    server_fd =open(SERVER_FIFO,O_RDONLY);
    if(server_fd ==-1){
        printf("Error open fifo \n");
        unlink(SERVER_FIFO);
        exit(EXIT_FAILURE);
    }
    while (1){
        memset(buff, 0, BUFF_SIZE);
        //Mo server, doc yeu cau client
        st_read = read(server_fd, buff, BUFF_SIZE);
        
        if(st_read>0){
            printf("buff recevied: %s\n",buff);
            char client_fifo[100];
            char service_request[100];
            char key[100];
            sscanf(buff, "%s %s %s", client_fifo, service_request, key);
            printf("kep:%s\n",key);
            printf("service:%s\n", service_request);
            printf("client fifo: %s \n",client_fifo);
            int accept_request =1;
            if(strcmp(key, "KEY_VALUE")!=0){
                printf("connection rejected: Invalid key\n");
                accept_request =0;
            }
            if(cout_connection>= COUNT_MAX){
                printf("Connection reject: max connection reached \n");
                accept_request =0;
            }
            //send repose to client
            client_fd = open(client_fifo, O_WRONLY);
            if(client_fd ==-1){
                printf("error openinng client FIFO\n");
                continue;
            }
            if(accept_request ==1){
                cout_connection ++;
                write(client_fd, "accept",strlen("accept")+2);
                printf("connection accept. current connection: %d\n",cout_connection);
            }
            else{
                write(client_fd, "reject",strlen("reject")+1);
            }
            close(client_fd);
            
        }
    }
    close(server_fd);
    return 0;


}