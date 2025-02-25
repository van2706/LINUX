#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<pthread.h>
pthread_t pthread1, pthread2;
typedef struct{
    char name[30];
    char msg[30];
}pthread_data;
void *pthread_handle1(void *aggv){
    pthread_data *th = (pthread_data *)aggv;
    printf("name : %s\n", th->name);
    printf("in pthread 1\n");
    //sleep(2);
    pthread_exit(NULL);
}
void *pthread_handle2(void *aggv){
    sleep(5);
    pthread_exit(NULL);
    while(1){
        printf("thread handle 2\n");
        sleep(1);
    }
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
    if (rm = pthread_create(&pthread2, NULL, &pthread_handle2, &data)){
        printf("pthread_create(), error = %d\n", rm);
        return -1;
    }
    sleep(5);
   // pthread_cancel(pthread2);
    pthread_join(pthread2, NULL);
    printf("termination\n");
    //while(1);
    return 0;
}