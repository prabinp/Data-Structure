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

int search(int in[], int start, int end, int value){
	for(int i=start; i<=end; i++){
		if(in[i] == value){
			return i;
		}
	}
}

Node *insert(int pre[], int in[], int start, int end){
	
	static int preIndex = 0;
	
	if(start > end){
		return NULL;
	} else {
		
		Node *temp = createNode(pre[preIndex++]);
	
		int inIndex = search(in, start, end, temp->data);
	
		if(start == end){
			return temp;
		} else {
			temp->left = insert(pre, in, start, inIndex-1);
			temp->right = insert(pre, in, inIndex+1, end);
			return temp;
		} 
	}
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
	
	Node *root = NULL;
	
	int data;
	int length = 7;  
	
	int in[length], pre[length];
	
	cout <<"\nEnter the preorder - ";
	for(int i=0; i<length; i++){
		cin >> pre[i];
	}
	
	cout <<"\nEnter the inorder - ";
	for(int i=0; i<length; i++){
		cin >> in[i];
	}
	
	root = insert(pre, in, 0, length-1);
	
	preorder(root);
	cout << endl;
	
	inorder(root);
	cout << endl;
	
	return 0;
}


