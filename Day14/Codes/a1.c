#include<stdio.h>
#include<unistd.h>
int main(){
	printf("Hello World");
	int f=fork();
	int p=getpid();
	
	printf("\nThe pid is %d\n",p);
	printf("The fork is %d\n",f);
	
	return 0;
}