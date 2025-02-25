#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define SP 5

pthread_t thread1,thread2;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
typedef struct{
    char  name[30];
    char message[30];
}pthread_data;
int count =0;  // gia tri shared resoure

void *pthread_handle1(void *data_in){
    pthread_data *data =(pthread_data *)data_in;
    printf("thread 1 xin chao \n");
    printf("message : %s\n", data->message);
    pthread_mutex_lock(&lock1);
    while(count<SP){
        count ++;
        printf("count create :%d\n", count);
    }
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}
void *pthread_handle2(void *data_in){
    pthread_data *data =(pthread_data *)data_in;
    printf("thread 2 xin chao \n");
   // pthread_mutex_lock(&lock2);
    printf("gia tri shared resource : %d\n", count);
    //pthread_mutex_unlock(&lock2);
    pthread_detach(thread2);
}
int main(){
    pthread_data data;
    strncpy(data.name, "dinhvan", sizeof(data.name));
    strncpy(data.message, "xin chao", sizeof(data.message));
    // !=0
    if(pthread_create(&thread1,NULL, &pthread_handle1, &data)){
        printf("errorcreate thread 1\n");
        return -1;
    }
    if(pthread_create(&thread2,NULL,&pthread_handle2,&data)){
        printf("error thread 2\n");
        return -1;
    }
    pthread_mutex_lock(&lock);
        while(1){
            pthread_cond_wait(&cond,&lock1);
            if(count == SP){
                printf("Global valiable : %d\n", count);
                break;
            }
        }
    pthread_mutex_unlock(&lock);
    pthread_join(thread1,NULL);
    //printf("gia tri count tu main :%d\n", count++);
    printf("............\n");
    return 0;
}