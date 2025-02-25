#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#define path_name  "./fifo"
#define BUFF_SIZE 1024
int main(){
    char buff[BUFF_SIZE];
    int fd;
   // mkfifo ([path_name] , [permission]);
   mkfifo(path_name, 0666);
   while(1){
    printf("message to consumer: "); fflush(stdin);
    fgets(buff,BUFF_SIZE, stdin);
    fd  = open(path_name, O_WRONLY);
    write(fd,buff, strlen(buff)+1);
    close(fd);
   }
   return 0;
}
