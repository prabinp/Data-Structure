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

bool printAncestor(Node *root, int target){
	
	if(root == NULL){
		return false;
	}
	
	if(root->data == target){
		return true;
	}	
	
	if(printAncestor(root->left, target) || printAncestor(root->right, target)){
		cout << root->data <<" ";
		return true;
	}
	
	return false;
}

int main(){
	
	int data, k;
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
	cin >> k;
	cout << endl;
	
	printAncestor(root, k);
	cout << endl;
	
	return 0;
}

