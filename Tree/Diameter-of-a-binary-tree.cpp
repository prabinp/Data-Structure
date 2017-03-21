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

int max(int a, int b){
	return (a > b) ? a : b;
}

int height(Node *root){
	
	if(root == NULL){
		return 0;
	} else {
		int l = height(root->left);
		int r = height(root->right);
		
		l += 1;
		r += 1;
		
		max(l, r);
	}
}

int diameter(Node *root){
	if(root == NULL){
		return 0;
	} else {
		int lh = height(root->left);
		int rh = height(root->right);
		
		int dl = diameter(root->left);
		int dr = diameter(root->right);
		
		return max(lh + rh + 1, max(dl, dr));
	}
}

void inorder(Node *root){
	if(root != NULL){
		inorder(root->left);
		cout << root->data <<" ";
		inorder(root->right);
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
	
	inorder(root);
	cout << endl;
	
	cout << height(root) << endl;
	cout << diameter(root) << endl;
	
	return 0;
}






