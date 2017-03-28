#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} Node;

Node *createNode(int data){
	Node *temp = (Node *) malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node *insert(Node *root, int data){
	
	Node *parent, *current;
	Node *temp = createNode(data);
	
	if(root == NULL){
		root = temp;
	} else {
		current = root;
		while(true){
			parent = current;
			if(current->data > data){
				current = current->left;
				if(current == NULL){
					parent->left = temp;
					break;
				} 
			} else {
				current = current->right;
				if(current == NULL){
					parent->right = temp;
					break;
				}
			} 
		}
	}
	
	return root;
}

Node *findMin(Node *root){
	if(root != NULL){
		while(root->left != NULL){
			root = root->left;
		}
		return root;
	}
}

Node *deleteNode(Node *root, int data){
	
	if(root != NULL){
		if(data < root->data){
			root->left = deleteNode(root->left, data);
		} else if(data > root->data){
			root->right = deleteNode(root->right, data);
		} else {
			if(root->left == NULL && root->right == NULL){
				free(root);
				root = NULL;
			} else if(root->left == NULL){
				Node *temp = root;
				root = root->right;
				free(temp);
			} else if(root->right == NULL){
				Node *temp = root;
				root = root->left;
				free(temp);
			} else {
				Node *temp = findMin(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}
	}
	return root;
}

void inorder(Node *root){
	if(root != NULL){
		inorder(root->left);
		cout << root->data <<" ";
		inorder(root->right);
	}
}

void preorder(Node *root){
	if(root != NULL){
		cout << root->data <<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main(){
	
	int data;
	Node *root = NULL;
	
	while(1){
		cin >> data;
		if(data == 0){
			break;
		} else {
			root = insert(root, data);
		}
	}
	
	inorder(root);
	cout << endl;
	
	preorder(root);
	cout << endl;
	
	cout <<"\nEnter the node - ";
	cin >> data;
	cout << endl;
	
	root = deleteNode(root, data);
	
	inorder(root);
	cout << endl;
	
	preorder(root);
	cout << endl;
	
	return 0;
}








