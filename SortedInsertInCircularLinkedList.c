
// Sorted insert in circular list

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} Node;

Node *createNode(int data){
	Node *temp = (Node *) malloc(sizeof(Node));
	temp->data = data;
	return temp;
}

Node *insert(Node *head, int data){
	
	Node *temp = createNode(data);
	Node *current = head;
	
	if(current == NULL){
		temp->next = temp;
		head = temp;
	} else if(current->data >= temp->data){
		
		while(current->next != head){
			current = current->next;
		}
		current->next = temp;
		temp->next = head;
		head = temp;
	} else {
		while(current->next != head && current->next->data < temp->data){
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
	}
	
	return head;
}

void printList(Node *head){
	
	Node *current;
	if(head != NULL){
		current = head;
		do {
			printf("%d ", current->data);
			current = current->next;
		} while(current != head);
	}
}

int main(){
	
	int data;
	Node *head = NULL;
	
	while(1){
		printf("\nEnter the data - ");
		scanf("%d", &data);
		
		if(data == 0){
			break;
		} else {
			head = insert(head, data);
		}
	}
	
	printList(head);
}
