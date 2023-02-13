#include <stdio.h>
#include <stdlib.h>

/* This file includes stack data structure which written with LinkedList*/

struct n {
	struct n* next;
	int data;
}typedef node;

void print(node* root){
	while(root!=NULL){
		printf("Stack: %d ",root->data);
		root=root->next;
	}
}
int pop(node **ptr){
	node * root = *ptr;
	if(root==NULL){
		printf("Stack is empty. ");
		return -1;
	}
	if(root->next==NULL){
		int rvalue = root->data;
		free(root);
		*ptr = NULL;
		return rvalue;
	}
	node* iter = root;
	while(iter->next->next!=NULL)
		iter =iter->next;
	node* temp= iter->next;
	int rvalue = temp->data;
	iter->next = NULL;
	free(temp);
	return rvalue;
}


node* push(node* root,int a){
	if(root==NULL){
		root = (node*)malloc(sizeof(node));	
		root->data = a;
		root->next = NULL;
		return root;
	}
	node* iter = root;
	while(iter->next!=NULL)
			iter=iter->next;
	node* temp = (node*)malloc(sizeof(node));
	temp->data = a;
	temp->next = NULL;
	iter->next = temp;
	return root;
}

int main(int argc, char *argv[]) {
	
	node *s = NULL;
	s = push(s,10);
	s= push(s,20);
	
	printf("popped: %d ",pop(&s));
	s= push(s,30);
	printf("popped: %d ",pop(&s));
	printf("popped: %d ",pop(&s));
	printf("popped: %d ",pop(&s));
	printf("popped: %d ",pop(&s));




	
	return 0;
}
