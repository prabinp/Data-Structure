#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
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
	Node *current, *parent;
	
	if(root == NULL){
		root = temp;
	} else {
		current = root;
		while(1){
			parent = current;
			if(data < current->data){
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

void morrisTraversal(Node *root){
	
	Node *pre, *current;
	
	if(root == NULL){
		return;
	} else {
		current = root;
		
		while(current != NULL){
			if(current->left == NULL){
				cout << current->data <<" ";
				current = current->right;
			} else {
				pre = current->left;
				while(pre->right != NULL && pre->right != current){
					pre = pre->right;
				}
				if(pre->right == NULL){
					pre->right = current;
					current = current->left;
				} else {
					pre->right = NULL;
					cout << current->data <<" ";
					current = current->right;
				}
			}
		}
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
	
	morrisTraversal(root);
	cout << endl;
	
	return 0;
}
