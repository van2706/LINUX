#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/unix_socket"
#define BUFFER_SIZE 1024

int main(int agr, char *agrv[]){
    int server_fd, client_fd;
    struct sockaddr_un server_addr, client_addr;
    socklen_t clientlen;


    char buffer[BUFFER_SIZE];
    // tao socket voi stream
    server_fd = socket(AF_UNIX, SOCK_STREAM,0);
    if(server_fd == -1){
        printf("create socket error");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_PATH, sizeof(server_addr.sun_path)-1);
    
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))==-1){
        printf("bind error\n");
        exit(EXIT_FAILURE);
    }
    if(listen(server_fd, 5)==-1){
        printf("listen error");
        exit(EXIT_FAILURE);
    }
    printf("dang lang nghe tai %s\n ",SOCKET_PATH);
    clientlen = sizeof(client_addr);
        client_fd = accept(server_fd,(struct sockaddr *)&client_addr,&clientlen);
    if(client_fd ==-1){
        printf("create client error \n");
        exit(EXIT_FAILURE);
    }
    memset(buffer,0, BUFFER_SIZE);
    read(client_fd, buffer,BUFFER_SIZE);
    printf("buffer : %s\n", buffer);

    char *chuoi = "xin chao";
    int byte = write(server_fd, chuoi, strlen(chuoi));
    sleep(1);
    if(byte >0){
        printf("server gui thanh cong");
    }
    else {
        printf("server gui that bai");
    }
    
        // Đóng kết nối
        close(client_fd);
        close(server_fd);
        unlink(SOCKET_PATH); // Xóa file socket sau khi sử dụng
    return 0;
}