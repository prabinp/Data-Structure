#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} Node;

Node *getNode(int data){
	Node *temp = (Node *) malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

Node *insert(Node *root, int data){

	Node *temp = getNode(data);
	if(root == NULL){
		root = temp;
	} else if(data <= root->data){
		root->left = insert(root->left, data);
	} else if(data >= root->data){
		root->right = insert(root->right, data);
	}
	
	return root;
}

void preorder(Node *root){
	if(root == NULL){
		return;
	} else {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int main(){
	
	int value;
	Node *root = NULL;
	
	while(1) {
		printf("\nEnter the data - ");
		scanf("%d", &value);
		
		if(value == 0){
			break;
		} else {
			root = insert(root, value);
		}
	}
	
	inorder(root);	
	return 0;
}
