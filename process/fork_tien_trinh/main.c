#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main (int argc, char *arg[]){
	pid_t child_pid;
	pid_t child_pid2;
	int counter =1;
	printf("gia tri ban dau :%d",counter);
	child_pid = fork();
	child_pid2 = fork();
	if(child_pid >=0){
		if(child_pid ==0){
	printf("\n in process child 1 counter: %d \n", ++counter);
	printf("my PID child 1: %d, my parent PID is: %d\n", getpid(), getppid());
		}
	else{
		printf("\n in process parent counter: %d \n", ++counter);
		printf("my PID parent: %d\n", getpid());
	}
	}
	else{
		printf("\n ERROR\n");
	}	
        if(child_pid2 >=0){
                if(child_pid2 ==0){
       printf("\n in process child 2 counter: %d \n", ++counter);
        printf("my PID 2: %d, my parent PID is: %d\n", getpid(), getppid());
                }
	}
        else{
                printf("\n in process parent counter: %d \n", ++counter);
                printf("my PID parent: %d\n", getpid());
        }

return 0;
}
