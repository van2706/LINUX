#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define server_fifo "./server_fifo"
#define MASS_SIZE 1024
#define MASS_ACCEPT 5
int main(){
    char buffer[MASS_SIZE];
    int countaccept =0;
    int fd_server, fd_client;
   if( mkfifo(server_fifo,0666)==-1){
    perror("server fifo error ");
   }
   while(1){
   fd_server = open(server_fifo,O_RDONLY);
   if(fd_server ==-1){
    perror("open error");
    exit(EXIT_FAILURE);
   }
   ssize_t bytes_read = read(fd_server, buffer, MASS_SIZE);
   if (bytes_read <= 0) {
       // Không có client hoặc lỗi đọc
       close(fd_server);
       usleep(500000);  // Chờ 500ms rồi thử lại
       continue;
   }
   char client_fifo[40];
   char request[40];
   char key[40];
   sscanf(buffer,"%s %s %s",client_fifo,request,key);
   printf("request receive :%s\n", request);
   printf("client name : %s\n",client_fifo);
   int accept =1;
   if(strcmp(key, "2706")!= 0){
        accept =0;
        printf("value key failed\n");
   }
   if(accept> MASS_ACCEPT){
        accept =0;
        printf("number client connect over");
   }
   fd_client = open(client_fifo,O_WRONLY);
   if(fd_client ==-1){
     perror("open client error: ");
     exit(EXIT_FAILURE);
    }
   if(accept ==1 ){
        countaccept++;
        write(fd_client,"accept", strlen("accept")+1);
        printf("client connect accept, device number :%d\n", countaccept);
   }
   else{
    write(fd_client,"reject", strlen("reject")+1);
    printf("client connect reject ");
    }
    close(fd_client);
    close(fd_server);
     }
    
    return 0;
}