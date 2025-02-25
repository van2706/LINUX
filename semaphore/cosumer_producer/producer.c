#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int main(){
    int slotcurrent;
    //char *buffer = (char *)mmap(NULL , sizeof(int)*BUFFER_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED,-1,0);
    // create shared semaphore
    sem_t *mutex = (sem_t *)mmap(NULL,sizeof(sem_t *),PROT_READ |PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0);
    sem_t *empty =(sem_t *)mmap(NULL,   sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
    sem_t *full =(sem_t *)mmap(NULL,   sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);

    if (mutex == MAP_FAILED || empty == MAP_FAILED || full == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }
    sem_init(mutex, 1, 1);
    sem_init(empty,1, BUFFER_SIZE);
    sem_init(full,1,0);

    pid_t producer;
    pid_t consumer;
    srand(time(NULL));
    if(producer = fork()==0){
        while (1){
            sem_wait(empty);
            sem_wait(mutex);
            printf("producer creates something\n");
            sem_post(mutex);
            sem_post(full);

            // sleep between 0 and 3 seconds
            
            sleep(rand() % 5);

        }
    }
    if(consumer = fork()==0){
        while(1){
            sem_wait(full);
            sem_wait(mutex);
            
            printf("consumer takes something\n");
            sem_post(mutex);
            sem_post(empty);

             // sleep between 3 and 8 seconds
             //srand(time(NULL));
            sleep(sleep(3)+rand()%5);

        }
    }
    // parent
    else{
        while(1){
            sleep(1);
            sem_getvalue(full, &slotcurrent);
            printf("Items in the bufer :%d/%d\n", slotcurrent, BUFFER_SIZE);
        }
    }
    return 0;
}