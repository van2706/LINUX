#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

pthread_t pthread1, pthread2;
typedef struct {
	char name[30];
	char msg[30];
}pthread_data;
void *thread_handle(void *argv){
	pthread_t td = pthread_self();
	pthread_data *data = (pthread_data *)argv;
	if(pthread_equal(td, pthread1)){
		printf("I'm thread 1\n");
		}
	else{
		printf("I'm thread 2\n");
		printf("Hello %s, welcom to join %s\n", data->name, data->msg);
	}
}

int main(int arg, char *argc[]){
	pthread_data data = {0};
	int rm;
	strncpy(data.name, "dinhvan", sizeof(data.name));
	strncpy(data.msg, "chao thread\n", sizeof(data.msg));
	if(rm = pthread_create(&pthread1, NULL, &thread_handle, NULL)){
		printf("pthread_create() error number = %d\n",rm);
		return -1;
	}
	sleep(2);
	if(rm = pthread_create(&pthread2, NULL,&thread_handle, &data)){
	printf("pthread_create() error number=%d\n", rm);
	}
	sleep(5);
	return 0;
	}
