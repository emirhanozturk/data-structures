#include <stdio.h>
#include <stdlib.h>

/* This file includes circular LinkedList implementation */

struct n{
	int x;
	struct n* next;
}typedef node;


void printer(node* r){
	node* iter = r;
	printf(" %d ",iter->x);
	iter=iter->next;
	while(iter!=r){
		printf(" %d ",iter->x);
		iter=iter->next;
	}
}

void add(node* r,int x){
	node* iter = r;
	while(iter->next!=r){
		iter=iter->next;
	}
	iter->next = (node*)malloc(sizeof(node));
	iter->next->x = x;
	iter->next->next = r;
}

node* addSequential(node* r,int x){
	if(r==NULL){ // if linkedlist is empty
		r=(node*)malloc(sizeof(node));
		r->next = r;
		r->x = x;
		return r;
	} 
	if(r->x > x){ // if the first data of linkedlist is greater than value which we add.
			node* temp = (node*)malloc(sizeof(node));
			temp->x = x;
			temp->next = r;
			node* iter = r;
			while(iter->next!=r){
				iter=iter->next;
			}
			iter->next = temp;
			return temp;
		}
	node* iter =r;
	while(iter->next != r && iter->next->x < x){
		iter=iter->next;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->x = x;
	return r;
	
}

int main(int argc, char *argv[]) {
	
	node* root;
	root = NULL;
	root = addSequential(root,400);
	root = addSequential(root,500);
	root = addSequential(root,25);
	root = addSequential(root,10);
	root = addSequential(root,60);

	printer(root);
	
	return 0;
}
