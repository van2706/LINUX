#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define FILE_PATH "./shmfile"
#define SHM_SIZE 1024

int main(int arg, char *argv[]){
    key_t key;
    int shmid;
    char *shmaddr;
    // tạo key
    key = ftok(FILE_PATH, 65);
    if(key ==-1){
        printf("ftok failed");
        exit(EXIT_FAILURE);
    }
    // tạo bộ nhớ chung
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if(shmid ==-1){
        printf ("shmget failed");
        exit(EXIT_FAILURE);
    }
    // gắn bộ nhớ dùng chung vào tiến trình
    shmaddr= (char *)shmat(shmid, (void*)0, 0);
    printf("Data read from memory :%s\n", shmaddr);

    // ghi du lieu vao bo nho chung
    printf("write : ghi du lieu vao bo nho chung\n");
    strcpy(shmaddr, "xin chao shared memory");
    /** 
     * int shmdt(const viid *shmaddr)
     * @brief Detaching the shared memory segment from the address space of the calling process
    
    
    */
   // tách bộ nhớ chung khỏi tiến trình.
   shmdt(shmaddr);
   // xóa bộ nhớ dùng chung(don dẹp sau khi su dung)
   // shctl (shmid, IPC_RMID, NULL);
    return 0;
}
    /**
    * @param[in] shmid shared memory
    
    */
    