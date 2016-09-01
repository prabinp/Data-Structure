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

void inorder(Node *root){
	if(root == NULL){
		return;
	} else {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void postorder(Node *root){
	if(root == NULL){
		return;
	} else {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
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

int findMin(Node *root){
	if(root == NULL){
		printf("\nEmpty\n");
		return -1;
	} else {
		while(root->left != NULL){
			root = root->left;
		}
		
		return root->data;
	}
}

int findMax(Node *root){
	if(root == NULL){
		printf("\nEmpty\n");
		return -1;
	} else {
		while(root->right != NULL){
			root = root->right;
		}
		
		return root->data;
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
	
	printf("\nPreorder - ");
	preorder(root);
	
	printf("\nInorder - ");
	inorder(root);
	
	printf("\nPostorder - ");
	postorder(root);
	
	printf("\nMin value - %d", findMin(root));		
	printf("\nMax value - %d", findMax(root));

	return 0;
}
