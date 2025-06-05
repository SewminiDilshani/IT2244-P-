//writer

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SHM_SIZE 1024 //size if shared memory segment

int main(){
	key_t key =  ftok("shmfile",114); // generate unique key
	int shmid = shmget(key,SHM_SIZE, IPC_CREAT| 0666); //create shared memeory segmewnt
	
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,NULL,0); //Attach to shared memory
	if(shmaddr == (char*) -1) {
		perror("shmat");
		exit(1);
	}
	
	printf("Write Data: ");
	fgets(shmaddr, SHM_SIZE,stdin); //write data to shared memory
	printf("Data written in memory: %s\n", shmaddr);
	
	shmdt(shmaddr);  //Detach from shared memory
	
	return 0;
}