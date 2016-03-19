
/* This is a single link list insertion at the last program implemented in c
 * Author - Prabin Pramanik
 */


#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} Node;

Node * insert(Node * start, int data);

void display(Node * start);

int main(){
	
	int value;
	
	Node * start;
	start = NULL;
	
	printf("\nEnter the data(0 to terminate)\n");
	
	while(1){
		
		scanf("%d",&value);
		
		if(value==0){
			break;
		} else {
			
			start = insert(start, value);
		}
		
	}
	
	display(start);
	
	return 0;
}

Node * insert(Node * start, int data){
	
	Node *head, *temp;
	
	temp = (Node *)malloc(sizeof(Node *));
	
	temp->data = data;
	temp->next = NULL;
	
	if(start==NULL){
		start = temp; 
	} else {
		
		head = start;
		
		while(head->next!=NULL){
			head=head->next;
		}
		
		head->next = temp;
		head = temp;
	}
	return start;
}


void display(Node * start) {
	
	while(start!=NULL){
		printf("%d\t", start->data);
		start = start->next;
	}
}
