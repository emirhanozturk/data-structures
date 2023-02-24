#include <stdio.h>
#include <stdlib.h>

/* This file includes singly LinkedList implementation */

struct n{
	int x;
	struct n* next;
}typedef node;

void add(node* r,int x){
	while(r->next!=	NULL){
		r=r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
	
}

void printer(node* r){
	while(r!=NULL){
		printf(" %d ",r->x);
		r=r->next;
	}
	printf(" \n ");
}

node* addSequential(node* r,int x){
	if(r==NULL){ // if linkedlist is empty
		r=(node*)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;
		return r;
	}
	if(r->x > x){ // if the first data of linkedlist is greater than value which we add.
			node* temp = (node*)malloc(sizeof(node));
			temp->x = x;
			temp->next = r;
			r = temp;
			return temp;
		}
	node* iter =r;
	while(iter->next != NULL && iter->next->x < x){
		iter=iter->next;
	}

	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->x = x;
	return r;
	
}

node* delete(node* r,int x){
	node* iter = r;
	node* temp;
	if(r->x == x){
		temp = r;
		r=r->next;
		free(temp);
		return r;
	}
	while(iter->next!=NULL && iter->next-> x !=x ){
		iter=iter->next;
	}
	if(iter->next==NULL){
		printf("Sayi bulunamadi \n");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return r;
}

int main(int argc, char *argv[]) {
	node* root;
	root = NULL;
	root = addSequential(root,400);
	root = addSequential(root,25);
	root = addSequential(root,10);
	printer(root);
	root = delete(root,25);
	root = addSequential(root,60);
	printer(root);
	root = delete(root,10);
	root = delete(root,10);
	printer(root);
	root = addSequential(root,22);
	printer(root);
	root = addSequential(root,35);
	printer(root);
	root = addSequential(root,45);
	printer(root);
	root = addSequential(root,20);
	printer(root);
	root = addSequential(root,99);
	printer(root);
	root = delete(root,99);
	printer(root);
	root = delete(root,99);
	printer(root);
	root = delete(root,35);
	printer(root);
	
	
	
	return 0;
}
