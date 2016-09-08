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

void printLevelOrder(Node *root){
	int height = findHeight(root);
	int i;
	for(i=1; i<=height; i++){
		printGivenLevel(root, i);
	}
}

void printGivenLevel(Node *root, int level){
	if(root == NULL){
		return;
	} else if(level == 1){
		printf("%d ", root->data);
	} else {
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}
}

Node* findMin(Node *root){
	if(root == NULL){
		printf("\nEmpty\n");
		return;
	} else {
		while(root->left != NULL){
			root = root->left;
		}
		
		return root;
	}
}

Node* findMax(Node *root){
	if(root == NULL){
		printf("\nEmpty\n");
		return;
	} else {
		while(root->right != NULL){
			root = root->right;
		}
		
		return root;
	}
}

int findHeight(Node *root){
	
	int lc = 0, rc = 0, height;
	Node *leftc, *rightc;
	
	if(root == NULL){
		return 0;
	} else {
		lc = findHeight(root->left);
		rc = findHeight(root->right);
		
		if(lc > rc){
			return (lc+1);
		} else {
			return (rc+1);
		}
	}
}

void search(Node *root, int data){
	
	Node *current = root;
	
	if(current != NULL){
		if(current->data ==  data){
			printf("\nFound\n");
			return;
		} else {
			if(data <= current->data){
				search(current->left, data);
			} else {
				search(current->right, data);
			}
		}
	}
}

Node *deleteNode(Node *root, int data){
	if(root == NULL){
		return root;
	} else if(data < root->data){
		root->left = deleteNode(root->left, data);
	} else if(data > root->data){
		root->right = deleteNode(root->right, data);
	} else {
		
		if(root->left == NULL && root->right == NULL){
			free(root);
			root=NULL;
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
	
	return root;
}

int main(){
	
	int value, ch;
	Node *root = NULL, *max, *min;
	
	while(1){
		printf("\n1 - Insert the elements");
		printf("\n2 - Preorder traversal");
		printf("\n3 - Inorder traversal");
		printf("\n4 - Postorder traversal");
		printf("\n5 - Level order traversal");
		printf("\n6 - Display the maximum element");
		printf("\n7 - Display the minimum element");
		printf("\n8 - Search an element");
		printf("\n9 - Find the height of the tree");
		printf("\n10 - Delete an element");
		
		printf("\n\nEnter your option - ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1: while(1) {
						printf("\nEnter the data - ");
						scanf("%d", &value);
		
						if(value == 0){
							break;
						} else {
							root = insert(root, value);
						}
					}
			break;
			
			case 2:	printf("\nPreorder - ");
					preorder(root);
			break;
			
			case 3: printf("\nInorder - ");
					inorder(root);
			break;
			
			case 4: printf("\nPostorder - ");
					postorder(root);
			break;
			
			case 5: printLevelOrder(root);
			break;
			
			case 6: max = findMax(root);
					printf("\nMax value - %d", max->data);
			break;
			
			case 7: min = findMin(root);
					printf("\nMin value - %d", min->data);
			break;
			
			case 8: printf("\nEnter the number to search - ");
					scanf("%d", &value);
	
					search(root, value);
			break;
			
			case 9: printf("\nHeight of the tree - %d\n", findHeight(root));
			break;
			
			case 10: printf("\nEnter the data to delete - ");
					 scanf("%d", &value);
	
					 root = deleteNode(root, value);
			break;
			
			default: printf("\nERROR: Wrong input\n");		 						
			break;				
		}
	}

	return 0;
}
