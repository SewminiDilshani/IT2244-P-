#include<stdio.h>
#include<unistd.h>
int main(){
	int b=fork();
	if(b==0){
		printf("Process B\n");
	}
	else{
		int c=fork();
		if(c==0){
			printf("Process C\n");
		}
		else{
			printf("Process A\n");
		}
	}
	
	return 0;
}