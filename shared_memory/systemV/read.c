#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

#define FILE_PATH   "./shmfile"
#define SHM_SIZE 1024

int main(){
    key_t key;
    int shmid;
    char *shmadd;

    key= ftok(FILE_PATH, 65);
    if(key ==-1){
        perror("key failed");
        exit(EXIT_FAILURE);
    }
    shmid = shmget(key,SHM_SIZE, 0666 | IPC_CREAT );
    shmadd = (char *)shmat(shmid, (void *)0,0);

    printf("data read shared memory: %s \n",shmadd);

    shmdt(shmadd);
    shmctl(shmid, IPC_RMID,NULL);


}