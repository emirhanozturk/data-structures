#include <stdio.h>
#include <stdlib.h>

/* This file include stack data structure which written with array. */

struct s {
	int size;
	int top;
	int *array;
}typedef stack;


stack* init(){
	stack *s = (stack*)malloc(sizeof(stack));
	s->array = NULL;
	s->size = 2;
	s->top = 0;
	return s;
}
int pop(stack *s){
	if(s->top<=0 || s->array == NULL){
		printf("array is empty.");
		return -1;
	}
	if(s->top<=s->size/4){
		int *array2 = (int*)malloc(sizeof(int)*s->size/2);
		int i;
		for(i = 0;i<s->top;i++){
			array2[i] = s->array[i];
		}
		free(s->array);
		s->array = array2;
		s->size /=2;
	}
	return s->array[--s->top];
}

void push(int a,stack *s){
	if(s->array == NULL){
		s->array = (int*)malloc(sizeof(int)*2);
	}
	if (s->top>=s->size-1){
		int *array2 = (int*)malloc(sizeof(int)*s->size*2);
		int i;
		for(i = 0;i<s->size;i++){
			array2[i] = s->array[i];
		}
		free(s->array);
		s->array = array2;
		s->size *=2;
	}
	s->array[s->top++] = a;
}

void print(stack *s){
	printf(" Size : %d",s->size);
	int i;
	for(i=0;i<s->top;i++){
		printf(" %d ",s->array[i]);
	}
}

int main(int argc, char *argv[]) {
	stack *s1 = init();
	stack *s2 = init();
	int i;
	for(i=0;i<10;i++){
		push(i*10,s1);
	}
	print(s1);
	for(i=0;i<10;i++){
		push(pop(s1),s2);
	}
	print(s2);


	return 0;
}
