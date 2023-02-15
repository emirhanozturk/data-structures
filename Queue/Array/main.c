#include <stdio.h>
#include <stdlib.h>

/* This file includes queue implementation with array. */

int *array = NULL;
int front = 0,rear = 0,size = 2;

void enqueue(int a){
	if (array == NULL){
			array = (int*)malloc(sizeof(int)*size);
	}
	if(rear >=size) {
		size *=2;
		int *array2 = (int*)malloc(sizeof(int)*size);
		int i;
		for(i = 0;i<size/2;i++){
			array2[i] = array[i];
		}
		free(array);
		array = array2;
	}
	array[rear++] = a;
}

int dequeue(){
	if(rear == front){
		printf("Queue is empty.");
			return -1;
	}
	if(rear-front<size/4){
		int *array2 = (int*)malloc(sizeof(int)*size/2);
		int i;
		for (i=0;i<=rear-front;i++){
			array2[i] = array[i+front];
		}
		rear -= front;
		front = 0;
		free(array);
		size /=2;
		array = array2;
	}
	return array[front++];
}

void clear(){
	if (front == 0){
		return;
	}
	int i;
	for(i = 0;i<size;i++){
		array[i] = array[i+front];
	}
	rear = rear - front;
	front = 0;
}

int main(int argc, char *argv[]) {
	int i;
	for(i=0;i<20;i++){
		enqueue(i*10);
	}
	printf("Size: %d, Front: %d, Rear: %d",size,front,rear);
	for(i=0;i<13;i++){
		printf("Dequeued : %d ",dequeue());
	}
	printf("Size: %d, Front: %d, Rear: %d",size,front,rear);
	
	return 0;
}
