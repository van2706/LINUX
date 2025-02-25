#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#define MAX_DATA 30
    char msg1[] = "xin chao viet nam";
    char msg2[] = "toi muon biet thong tin cua ban";
    char msg3[] = "ban dang yeu toi phai khong";
    char msg4[] = "thoi toi hieu roi";
void func(int num){
    wait(NULL);
    printf("process termination: %d\n",num);
}

int main(){
     int fsd[2];
     char in_buff[MAX_DATA];
     int num_read =0;
    pipe (fsd);
    pid_t child;
    child = fork();
    if(child >=0){
        if(child ==0){
            printf("in process_child \n");
            if(close(fsd[1])==-1){
                printf("close write pipe \n");
            }
            while(1){
                num_read =read(fsd[0],in_buff, MAX_DATA);
                if(num_read ==-1){
                    printf("read_pipe_error\n");
                    exit(0);
                }
                else if(num_read==0){
                    printf("pipe_end\n");
                    break;
                }
                else {
                    printf("msg: %s \n", in_buff);
                }
            }
        }
        else{
            signal(SIGCHLD, func);
            printf("In parent process \n");
            write(fsd[1],msg1, MAX_DATA);
            write(fsd[1], msg2, MAX_DATA);
            write(fsd[1], msg3, MAX_DATA);
            if(close(fsd[1])==-1){
                printf("close pipe unsucess\n");
            }
            while(1);
        }   

    }
    else {
        printf("create child process unsucess \n");
        return -1;
    }
    return 0;
}