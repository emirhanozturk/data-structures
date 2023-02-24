#include <stdio.h>
#include <stdlib.h>

/* This file includes doubly LinkedList implemantation */

struct n{
	int x;
	struct n* next;
	struct n* prev;
}typedef node;

void printer(node* r){
	while(r!=NULL){
		printf(" %d ",r->x);
		r=r->next;
	}
	printf(" \n ");
}

node* addSequential(node* r,int x){
	if (r == NULL){
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->prev = NULL;
		r->x = x;
		return r;
	}
	if(r->x > x){
		node* temp = (node*)malloc(sizeof(node));
		temp->x = x;
		temp->next = r;
		r->prev = temp;
		temp->prev =NULL;
		return temp;
	}
	node* iter =r;
	while(iter->next != NULL && iter->next->x < x){
		iter=iter->next;
	}

	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->prev= iter;
	if(temp->next!=NULL){
		temp->next->prev = temp;
	}
	temp->x = x;
	return r;
}

node* delete(node* r,int x){
	node* iter = r;
	node* temp;
	if(r->x == x){
		temp = r;
		r=r->next;
		r->prev = NULL;
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
	if(iter->next){
		iter->next->prev = iter;	
	}
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
