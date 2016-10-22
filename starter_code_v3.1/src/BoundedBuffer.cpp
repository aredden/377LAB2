#include "BoundedBuffer.h"

//condition variables/lock and buffer info initialization
pthread_cond_t empty;
pthread_cond_t full;
pthread_mutex_t lock;
int count;
int last;
int size;
int * buffer;

BoundedBuffer::BoundedBuffer(int N){
	//initalize count of items, last item, and size of buffer
	count = 0;
	last = 0;
	size = N;
	//make buffer of size N
	buffer = (int *)malloc(sizeof(int)*N);

	//initilize lock and full/empty condition variables
	pthread_mutex_init(&lock,NULL);
	pthread_cond_init(&full,NULL);
	pthread_cond_init(&empty,NULL);
}

void BoundedBuffer::append(int data){

	//lock buffer for anyone trying to access
	pthread_mutex_lock(&lock);
	//if the buffer is full, wait in empty cond variable
	if(count == size){
		pthread_cond_wait(&empty,&lock);
	}
	//add data to the buffer
	buffer[last] = data;
	last= (last+1)%size;
	count++;
	//wake up any waiting threads who want to remove
	pthread_cond_signal(&full);
	//unlock the buffer
	pthread_mutex_unlock(&lock);
}

int BoundedBuffer::remove(){
	pthread_mutex_lock(&lock);
	//if the buffer is empty, have the thread wait
	if(count == 0){
		pthread_cond_wait(&full,&lock);
	}
	//remove a valu from the buffer and update count
	int val = buffer[(last-count)%size];
	count = count-1;

	//wake up waiting append threads
	pthread_cond_signal(&empty);
	//unlock buffer
	pthread_mutex_unlock(&lock);
	//return the value removed
	return val;
}

bool BoundedBuffer::isEmpty(){
	//TODO: check is the buffer is empty
	return count==0;
}
