#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include<sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#define server_fifo "./server_fifo"
#define MASS_SIZE 1024
int main(){
    char client_fifo[40];
    char buffer[MASS_SIZE];
    sprintf(client_fifo,"./HTTP_%d",getpid());
    char key[40]="2706";
    char request[40]= "I_LOVE_YOU";
    sprintf(buffer,"%s %s %s",client_fifo,request,key);
    int fsd = open(server_fifo,O_WRONLY);
    if(fsd ==-1){
        perror("open error");
        exit(EXIT_FAILURE);
       }
    write(fsd,buffer,MASS_SIZE);

    //
    mkfifo(client_fifo,0666);
    memset(buffer,0,MASS_SIZE);
    int fd = open(client_fifo,O_RDONLY);
    if(fd ==-1){
        perror("open fifo failed");
        exit(EXIT_FAILURE);
    }
    read(fd,buffer,MASS_SIZE);
    if(strcmp(buffer,"accept")==0){
        printf("connect success\n");
    }
    else{
        printf("connect unsucess\n");
    }
    // send data
    close(fd);
    close(fsd);
    unlink(client_fifo);


    return 0;
}