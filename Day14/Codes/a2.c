#include<stdio.h>
#include<unistd.h>
int main(){
	
	fork();
	fork();
	
	printf("Hello World\n");
	
	return 0;
}