#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//A normal C function that is executed as a thread 
//When its name is specified in pthread_create()
void *helloWorld(void *vargp){
	sleep(1);
	printf("Hello WOrld!\n");
	return NULL;
}

int main(){
	pthread_t thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id,NULL,helloWorld,NULL);
	pthread_join(thread_id,NULL);
	printf("After Thread\n");
	exit(0);
}