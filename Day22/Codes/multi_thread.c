//Multi thread process

#include<stdio.h>
#include<pthread.h>

//Function to be executed by the thread
void* print_message(void* arg){
	char* message = (char*)arg;
	printf("%s\n",message);
	return NULL;
}

int main(){
	pthread_t thread1,thread2;
	
	//Create first thread
	pthread_create(&thread1,NULL,print_message,"Hello from Thread 1!");
	
	//Create second thread
	pthread_create(&thread2,NULL,print_message,"Hello from Thread 2!");
	
	//Wait for both threads to finish
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	printf("Both threads completed.\n");
	return 0;
	
}