#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define     BUFFER_SIZE 1024
#define SOCKET_PATH "/tmp/unix_socket"

int main(int agr, char *argv){
    int  sock_fd;
    struct sockaddr_un client_addr, server_addr;
    socklen_t serverlen;
    char buffer[BUFFER_SIZE];

    sock_fd = socket(AF_UNIX, SOCK_STREAM,0);
    if(sock_fd == -1){
        printf("create socket error");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_PATH, sizeof(server_addr.sun_path)-1);
    
    // ket noi voi server
    if(connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))==-1){
        printf("connect error\n");
        exit(EXIT_FAILURE);
    }
    // gui toi server
    char *message ="Hello client send";
    write(sock_fd, message, strlen(message) );
    printf("da gui den server\n");

    // nhan du lieu tu server
    memset(buffer, 0 , BUFFER_SIZE);
    int bytes_read = read(sock_fd, buffer, BUFFER_SIZE);
if (bytes_read > 0) {
    printf("data nhan tu server: %s\n", buffer);
    buffer[bytes_read] = '\0';  // Đảm bảo chuỗi kết thúc an toàn
} else {
    printf("Không nhận được dữ liệu từ server\n");
}
    

        // Đóng socket
        close(sock_fd);

    return 0;
}