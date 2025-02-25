#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

void main(){
	int counter = 2;
	int status, rm;
	pid_t pid_child;
	pid_child = fork();
	
	if(pid_child >=0){

		if(pid_child ==0){
			printf("in process child, my pid:  %d\n",getpid());
		while(1);
			//sleep(5);
		//exit(0);
		}
		else{
		printf("in process parent, my pid: %d\n", getpid());
		printf("use fork(): %d\n", pid_child);
		rm = wait(&status);
		if(rm ==-1){
			printf("wait() unscessful\n");
		}
		else{
			printf("in process parent, pid child is: %d\n",rm);
		}
		if(WIFEXITED(status)){
			printf("Normally termination, status= %d \n", WEXITSTATUS(status));
					}
		else if(WIFSIGNALED(status)){
			printf("killed by signal, value =%d \n", WTERMSIG(status));
		}
		}
	}
	else{
	printf("creat process unsucess\n");
	}
}

