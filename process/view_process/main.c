#include<stdio.h>
#include <stdlib.h>

void main(int arg, char *argv[]){
	int i;
	printf("so command line argument : %d \n", arg);
	for(i=0;i<arg ;i++){
		printf("arg[%d] : %s\n", i+1, argv[i]);
	}
}
