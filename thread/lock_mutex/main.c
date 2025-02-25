#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<pthread.h>
pthread_t pthread1, pthread2;
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;
typedef struct{
    char name[30];
    char msg[30];
}pthread_data;
int counter = 1;
void *pthread_handle1(void *aggv){

    pthread_data *th = (pthread_data *)aggv;
    pthread_mutex_lock(&lock1);
    printf("name : %s\n", th->name);
   // printf("in pthread 1\n");
    printf("thread handle 1, counter =%d\n", ++counter);
    sleep(5);
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}
void *pthread_handle2(void *aggv){
    pthread_mutex_lock(&lock1);
    printf("in thread_handle 2, counter = %d\n", ++counter);
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}
int main(){
    int rm;
    pthread_data data = {0};
    strncpy(data.name, "dinh van",sizeof(data.name));
    strncpy(data.msg, "LINUX_SERVER", sizeof(data.msg));
    if(rm = pthread_create(&pthread1, NULL, &pthread_handle1, &data)){
        printf("pthread_create(), error = %d\n",rm);
        return -1;
    }
    if (rm = pthread_create(&pthread2, NULL, &pthread_handle2, NULL)){
        printf("pthread_create(), error = %d\n", rm);
        return -1;
    }
   // sleep(5);
   // pthread_cancel(pthread2);
    pthread_join(pthread2, NULL);
    pthread_join(pthread1, NULL);
    printf("termination\n");
    //while(1);
    return 0;
}