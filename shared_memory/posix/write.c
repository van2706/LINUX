#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define SHM_NAME "/my_share_memory"
#define SHM_SIZE 1024

int main(){

    int shm_fd;
    void *shm_ptr;
    shm_fd = shm_open(SHM_NAME,O_CREAT | O_RDWR, 0666);

    if(shm_fd ==-1){
        perror("shm_open failed");
    }
    // đinh kích thước của shared memory
    ftruncate(shm_fd, SHM_SIZE);

    // Map shared memory vao tiến trình
    shm_ptr = mmap(0,SHM_SIZE,PROT_READ|PROT_WRITE, MAP_SHARED,shm_fd,0);
    if(shm_ptr ==MAP_FAILED){
        perror("mmap failded");
        exit(EXIT_FAILURE);
    }
    // ghi du lieu vao shared memory
    printf("writer : ghi du lieu vao shared memory .\n");
    strcpy((char *)shm_ptr, "xin chao toi den tu write");
    // un map bo nho nhung khong xoa(để reader đọc)
    munmap(shm_ptr,SHM_SIZE);
    close(shm_fd);
    printf("Writer: Dữ liệu đã ghi, chạy reader để đọc.\n");
    return 0;
}
