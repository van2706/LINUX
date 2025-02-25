#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>

#define BUFF_SIZE 1024
#define path_name "./fifo"
int main(){
    int fd;
    char buff[BUFF_SIZE];
    mkfifo(path_name, 0666);
    while(1){
        fd = open(path_name,O_RDONLY);
        read(fd,buff, BUFF_SIZE);
        printf("producer to :%s\n",buff);
        close(fd);
    }
    return 0;
}