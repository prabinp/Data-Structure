#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;


Node *init(Node *head){
	head = NULL;
	return head;
}


Node * insert(Node *head, int data){
	
	Node *start, *temp;
	
	temp = (Node *) malloc(sizeof(Node));
	temp->data = data;
	temp->next = head;
	
	
	if(head == NULL){
		temp->next = temp;
		head = temp;
	} else {
		start = head;
		
		while(start->next != head){
			start = start->next;
		}
		
		start->next = temp;
	}
	
	return head;
}

/*
void splite(Node *head){
	
}
*/


void printList(Node *head){
	
	Node *start;
	
	if(head != NULL){
		start = head;
		do {
			printf("%d\t", start->data);
			start = start->next;
		} while(start != head);	
	}
}


int main(){
	
	int value, ch;
	Node * head = init(head);
	
	printf("\nThis is circular linked list\n\n");
	
	while(1){
		
		printf("\n1 - Insert the data");
		printf("\n2 - Print the list");
		
		printf("\n\nEnter the option - ");
		scanf("%d", &ch);
		
		switch(ch){
			
			case 1: while(1){
						
						printf("\nEnter the data - ");
						scanf("%d", &value);			
						
						if(value == 0){
							break;
						}
						head = insert(head, value);
					}
			break;
			
			case 2: printList(head);
			break;
			
			default: printf("\nERROR: Wrong input\n");
			break;
		}
	}
	
	return 0;
}
