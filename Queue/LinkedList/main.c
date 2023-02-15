#include <stdio.h>
#include <stdlib.h>

/* This file includes queue implementation with linkedlist. */

struct n {
	struct n* next;
	int data;
}typedef node;

node* root = NULL;

void enqueue(int x){
	if (root ==NULL){
		root = (node*)malloc(sizeof(node));
		root->next = NULL;
		root->data = x;
		return;
	}
	node* iter = root;
	while(iter->next!=NULL){
		iter = iter->next;
	}
	node* temp = (node*)malloc(sizeof(node));
	iter->next = temp;
	temp->data = x;
	temp->next = NULL;
	
}

int dequeue(){
	if(root==NULL){
		printf("Queue is empty.");
		return -1;
	}
	int rvalue = root->data;
	node* temp = root;
	root = root->next;
	free(temp);
	return rvalue;
}

int main(int argc, char *argv[]) {
	int i;
	for(i=0;i<20;i++){
		enqueue(i*10);
	}
	for(i=0;i<13;i++){
		printf("Dequeued : %d ",dequeue());
	}
	for(i=0;i<20;i++){
		enqueue(i*10);
	}
	for(i=0;i<30;i++){
		printf("Dequeued : %d ",dequeue());
	}
	
	return 0;
	return 0;
}
