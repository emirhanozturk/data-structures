#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct n {
	int data;
	struct n* left;
	struct n* right;
}typedef node;

node * add(node* tree,int x){
	if(tree==NULL){
		node* root = (node*)malloc(sizeof(node));
		root->left = NULL;
		root->right=NULL;
		root->data = x;
		return root;
	}
	if(tree->data < x){
		tree->right = add(tree->right,x);
		return tree;
	}
	tree->left = add(tree->left,x);
	return tree;
}

void traversal(node* tree){
	if(tree==NULL)
		return;
	traversal(tree->left);
	printf(" %d ",tree->data);
	traversal(tree->right);
}

int search(node* tree,int x){
	if(tree==NULL)
		return -1;
	if(tree->data==x){
		return 1;
	}
	if(search(tree->left,x)==1){
		return 1;
	}
	if(search(tree->right,x)==1){
		return 1;
	}
	return -1;
}

int max(node* tree){
	while(tree->right!=NULL){
		tree = tree->right;
	}
	return tree->data;
}

int min(node* tree){
	while(tree->left!=NULL){
		tree = tree->left;
	}
	return tree->data;
}


int main(int argc, char *argv[]) {
	
	node* tree = NULL;
	tree = add(tree,12);
	tree = add(tree,200);
	tree = add(tree,190);
	tree = add(tree,213);
	tree = add(tree,56);
	tree = add(tree,24);
	tree = add(tree,18);
	tree = add(tree,27);
	tree = add(tree,28);
	traversal(tree);
	printf(" search: %d",search(tree,27));
	printf(" max: %d min: %d ",max(tree),min(tree));
	
	return 0;
}
