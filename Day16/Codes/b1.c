#include<stdio.h>
#include<stdlib.h>  //for exit()
#include<unistd.h>  //for sleep()

int main(){
	printf("Program started.\n");
	
	printf("Sleeping for 3 seconds...\n");
	sleep(3);  //pause for 3 seconds
	
	printf("Exiting the program.\n");
	exit(0);  //clean exit
}