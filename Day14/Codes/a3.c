#include<stdio.h>
#include<unistd.h>
int main(){
	int f=fork();
	
	if(f==0){
		printf("I am the child process\n");
	}
	else{
		printf("I am the parent process\n");
	}
	printf("Hello\n");
	return 0;
}