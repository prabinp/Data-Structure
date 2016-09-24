#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct tree{
	int data;
	struct tree *left, *right;
} Tree;

Tree *createNode(int data){
	Tree *temp = (Tree *) malloc(sizeof(Tree));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

int search(int start, int end, int inArray[], int data){
	for(int i=start; i<=end; i++){
		if(inArray[i] == data){
			return i;
		}
	}
}

Tree *buildTree(int inArray[], int preArray[], int start, int end){
	
	static int preIndex = 0;
	Tree *node = createNode(preArray[preIndex++]);
	
	if(start == end){
		return node;
	} else {
		int inIndex = search(start, end, inArray, node->data);
		
		node->left = buildTree(inArray, preArray, start, inIndex-1);
		node->right = buildTree(inArray, preArray, inIndex+1, end);
		
		return node;
	}
}

void postOrder(Tree *root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

int main(){
	
	int length;
	Tree *root;
	cout << "Enter the length - ";
	cin >> length;
	
	int inArray[length], preArray[length];
	
	cout << "\nEnter the inorder - ";
	
	for(int i=0; i<length; i++){
		cin >> inArray[i];
	}
	
	cout << "\nEnter the preorder - ";
	
	for(int i=0; i<length; i++){
		cin >> preArray[i];
	}
	
	root = buildTree(inArray, preArray, 0, length-1);
	
	cout << "\nEnter the postorder - ";
	postOrder(root);
	
	return 0;
}
