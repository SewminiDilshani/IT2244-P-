//Using threads to Compute Parts of a Sum(Parallel Sum)

#include<stdio.h>
#include<pthread.h>
#define SIZE 6

int arr[SIZE] = {1,2,3,4,5,6};
int sum1=0 , sum2=0;

void* sum_part1(void* arg){
	for(int i=0; i<SIZE/2; i++){
		sum1+=arr[i];
	}
	return NULL;
}

void* sum_part2(void* arg){
	for(int i=SIZE/2; i<SIZE; i++){
		sum2+=arr[i];
	}
	return NULL;
}

int main(){
	pthread_t t1,t2;
	
	pthread_create(&t1,NULL,sum_part1,NULL);
	pthread_create(&t2,NULL,sum_part2,NULL);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	printf("Total sum = %d\n",sum1 + sum2);
	return 0;
}