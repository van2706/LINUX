#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define SHM_NAME "/my_share_memory"
#define SHM_SIZE 1024

int main(){
    int shm_fd;
    void *shm_ptr;

    shm_fd = shm_open(SHM_NAME,O_CREAT |O_RDWR, 0666);
    if(shm_fd ==-1 ){
        perror("shm_open failed");
        exit(EXIT_FAILURE);
    }
    ftruncate(shm_fd, SHM_SIZE);
    shm_ptr = mmap(0,SHM_SIZE,PROT_READ|PROT_WRITE, MAP_SHARED,shm_fd,0);

    printf("du lieu nhan: %s\n", (char *)shm_ptr);
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);

    shm_unlink(SHM_NAME);
    printf("Reader: Đã xóa shared memory.\n");
    return 0;
}