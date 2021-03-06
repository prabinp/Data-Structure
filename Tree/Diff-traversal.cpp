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
	Node *temp = createNode(data);
	if(root == NULL){
		root = temp;
	} else {
		if(data < root->data){
			root->left = insert(root->left, data);
		} else {
			root->right = insert(root->right, data);
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

void postorder(Node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->data <<" ";
	}
}

int main(){
	
	int data;
	Node *root = NULL;
	
	while(1){
		cin >> data;
		if(data != 0){
			root = insert(root, data);
		} else {
			break;
		}
	}
	
	cout << "\nInorder - ";
	inorder(root);
	
	cout << "\nPreorder - ";
	preorder(root);
	
	cout << "\nPostorder - ";
	postorder(root);
	cout << endl;
	
	return 0;
}






