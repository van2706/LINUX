#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <errno.h>

#define POSIX_NAME "/name_app"


int main(){
    
    sem_t *sem;
    int current_value;
    sem = sem_open(POSIX_NAME,  O_CREAT |O_EXCL , 0666, 1);
    if(sem ==SEM_FAILED){
        if(errno != EEXIST){
            printf("Failed to open semaphore error %s\n", strerror(errno));
            return -1;
        }
    }
    sem = sem_open(POSIX_NAME, 0);
    if(errno != EEXIST){
        printf("Failed to open semaphore error %s\n", strerror(errno));
        return -1;
    }

    sem_getvalue(sem, &current_value);
    printf("current value %d\n", current_value);
    sem_close(sem);
    sem_unlink(&sem);
    return 0;
}