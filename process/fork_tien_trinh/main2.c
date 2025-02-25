#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void fun(){
	printf("Im in function\n");
	wait(NULL);
}
void main(){
	pid_t pid_child;
	int status;
	pid_child = fork();
	if(pid_child>=0){
		if(pid_child==0){
		printf(" in process chill with pid :%d\n", getpid());
		while(1);
		}
	else{
		printf("in process parent with pid: %d\n", getpid());
		signal(SIGCHLD, fun);
		printf("start\n");
		while(1);
	}
}
}
