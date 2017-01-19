#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
} Node;

Node *createNode(int data){
	Node *temp = (Node *) malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

Node *insert(Node *head, int data, int pos){
	
	Node *temp = createNode(data);
	Node *current = head;
	
	if(pos == 0){
		if(head == NULL){
			head = temp;
		} else {
			temp->next = head;
			head = temp;
		}
	} else if(pos == -1){
		if(head == NULL){
			head = temp;
		} else {
			while(current->next != NULL){
				current = current->next;
			}
			current->next = temp;
			temp->prev = current;
		}
	} else {
		while(current->data != pos && current->next != NULL){
			printf(". ");
			current = current->next;
		}
		if(current->data == pos){
			temp->next = current->next;
			current->next = temp;
			temp->prev = current;
			current->next->prev = temp;
		}
		else if((current->next->data == pos && current->next->next == NULL) || (current->data != pos && current->next->next == NULL)){
			current = current->next;
			current->next = temp;
			temp->prev = current;
		} 
	}
	return head;		
}

Node *deleteNode(Node *head, int data){
	
	Node *temp, *current = head;
	
	if(head != NULL){
		if(head->data == data){
			temp = head;
			head = head->next;
			head->prev = NULL;
			
			free(temp);
		} else {
			while(current->next->data != data && current->next->next != NULL){
				current = current->next;
			}
			
			if(current->next->data == data && current->next->next != NULL){
				current->next = current->next->next;
				current->next->prev = current;
			} else if(current->next->data == data && current->next->next == NULL){
				current->next = NULL;
			} else {
				return;
			}
		}
	}
	return head;
}

void printList(Node *head){
	
	if(head != NULL){
		while(head != NULL){
			printf("%d ", head->data);
			head = head->next;
		}
	}
}

int main(){
	
	int data, ch, pos;
	Node *head = NULL;
	
	while(1){
			
		printf("\n1 - To push");
		printf("\n2 - To append");
		printf("\n3 - To insert at position");
		printf("\n4 - To display");
		printf("\n5 - To delete");
		printf("\n6 - To Exit");
		
		printf("\n\nEnter your option - ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1: printf("\nEnter the data - ");
					scanf("%d", &data);
					head = insert(head, data, 0);
			break;
			
			case 2: 
					while(1){
						printf("\nEnter the data - ");
						scanf("%d", &data);
						
						if(data == 0){
							break;
						} else {
							head = insert(head, data, -1);
						}
					}
			break;
			
			case 3: printf("\nEnter the position element - ");
					scanf("%d", &pos);
					
					printf("\nEnter the data - ");
					scanf("%d", &data);
					
					head = insert(head, data, pos);
			break;
			
			case 4: printList(head);
			break;
			
			case 5: printf("\nEnter the element to delete - ");
					scanf("%d", &data);
					
					head = deleteNode(head, data);
			break;		
			
			case 6: exit(1);
			break;
			
			default: printf("\nERROR: Wrong input\n");
			break;				
		}	
	}
	
	return 0;
}

