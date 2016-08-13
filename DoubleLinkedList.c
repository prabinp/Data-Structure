#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
} Node;


Node *init(Node *head){
	head = NULL;
	return head;
}


Node *appand(Node *head, int data){
	
	Node *start, *temp;	
	
	temp = (Node *) malloc(sizeof(Node));
	
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	
	if(head == NULL){
		head = temp;
	} else {
		
		start = head;
		while(start->next != NULL){
			start = start->next;
		}
		
		start->next = temp;
		temp->prev = start;
		start = temp;
	}
	
	return head;
}


Node *SortedInsert(Node *head, int data){
	
	Node *temp, *start;

	temp = (Node *) malloc(sizeof(Node));
	temp->data = data;
	
	if(head==NULL){
		temp->prev = NULL;
		temp->next = NULL;
		
		return temp;
	} else {
		
		if(head->data >= data){
			temp->prev = NULL;
			temp->next = head;
			
			head->prev = temp;
			head = temp;
		} else {
			
			start = head;
			
			while(start->next != NULL && start->next->data <= data){
				start = start->next;
			}
			
			temp->prev = start;
			temp->next = start->next;
			
			if(start->next != NULL){
				start->next->prev = temp;
			}
			
			start->next = temp;
		}
	}
	
	return head;
}


void printList(Node *head){
	
	if(head == NULL){
		return;
	} else {
		printf("%d\t", head->data);
		printList(head->next);
	}
}



int main(){
	
	int ch, data;
	Node * head;
	head = init(head);
	
	while(1){
		
		printf("\n1 - Insert data");
		printf("\n2 - Display the list");
		printf("\n3 - Insert at sorted order");
		
		printf("\n\nEnter the choice - ");
		scanf("%d", &ch);
		
		switch(ch){
			
			case 1: while(1){
						
						printf("\nEnter the data - ");
						scanf("%d", &data);
						
						if(data == 0){
							break;
						}
						
						head = appand(head, data);
					}
			break;
			
			case 2: printList(head);
			break;
			
			case 3: printf("\nEnter the data - ");
					scanf("%d", &data);
					
					head = SortedInsert(head, data);
			break;
			
			default: printf("\nERROR Wrong input\n");
			break;
		}
	}
	
	return 0;
}
