#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} Node;


Node *init(Node *head){
	head=NULL;
	return head;
}


int search(Node* head, int pos){
	int i = 0;
	if(head != NULL){
		printf("\nSearching");
		while(i != pos){
			head = head->next;
			i++;
			printf(" . ");
		}
		
		printf("\n");
		
		if(i==pos){
			return 1;
		} else {
			return 0;
		}
		
	} else{
		return -1;
	}
}

int getCount(Node* head){
	
	int count = 0;
	
	if(head != NULL){
	
		while(head!=NULL){
			head = head->next;
			count++;
		}
		
		return count;	
	} else{
		return 0;
	}
}

Node* append(Node* head, int data){
	
	Node *start;
	Node *temp = (Node *) malloc(sizeof(Node));
	
	temp->data = data;
	temp->next = NULL;
	
	if(head == NULL){
		head = temp;
	} else {
		start = head;
		
		while(start->next != NULL){
			start = start->next;
		}
		
		start->next = temp;
		start = temp;
	}
	
	return head;
}


Node* push(Node* head, int data){
	
	Node *temp; 
	temp = (Node *) malloc(sizeof(Node));
	
	temp->data = data;
	temp->next = NULL;
	
	if(head != NULL){
		temp->next = head;
		head = temp;
	} else {
		return;
	}	
	
	return head;
}


Node * insertAtPosition(Node* head, int pos, int data){
	
	int i = 1;
	Node *temp, *start;
	
	temp = (Node *) malloc(sizeof(Node));
	
	temp->data = data;
	temp->next = NULL;

	if(pos == 0){
		
		temp->next = head;
		head = temp;
		return head;
	
	} else {

		start = head;
		
		while(i != pos){
		
			if(start == NULL){
				printf("Head is null");
				break;
			}
		
			start = start->next;
			i++;
		}
	
		if(i == pos){
			if(start->next == NULL){
				start->next = temp;
			} else {
				temp->next = start->next;
				start->next = temp;
			}
		}	 
	
		 else if(i != pos || head == NULL){
			printf("\nPostion is not found but still data is inserted\n");
			
			head->next = temp;
			head = temp;
			return head;
		}
	
		return head;
	}
}



Node* Delete(Node *head, int position) {
	
	int i = 1;
	Node *temp, *start;
	
	if(head != NULL){
		
		if(position == 0){
			
			temp = head;
			
			head = head->next;
			free(temp);
			
			return head;
		} else {
			
			start = head;
			while(i != position){
				
				if(start == NULL){
					printf("Head is null");
					break;
				}
				
				start = start->next;
				i++;
			}
			
			if(i == position){
				
				if(start->next == NULL){
					
					temp = head;
					
					while(temp->next->next != NULL){
						temp =  temp->next;
					}
					
					if(temp->next->next == NULL){
						temp->next = NULL;
						
						return head;
					}
					
				} else {
					start->next = start->next->next;
					return head;
				}
			}
			
			if(i != position || head == NULL) {
				
				printf("\nPosition is not found\n");
				return head;
			}
		}
		
	} else {
		printf("\nList is empty\n");
		return head;
	}
	
	return head;
}



void printList(Node *head){
	
	if(head != NULL){
		
		while(head!=NULL){
			printf("%d\t", head->data);	
			head = head->next;
		}
		printf("\n");
	} else {
		printf("\nList is empty\n");
		return;
	}
}


Node* deleteFromLast(Node *head){
	
	Node *temp;
	
	if(head != NULL){
		
		temp = head;
		
		while(temp->next->next != NULL){
			temp = temp->next;
		}
	
		if(temp->next->next == NULL){
			temp->next = NULL;
		}
			
	} else if(head->next == NULL){
		head = NULL;
	} else {
		printf("\nList is empty\n");
	}
	
	return head;
}


Node* deleteFromFirst(Node *head){
	
	Node *temp = head;
	
	if(head != NULL){
		head = head->next;
		free(temp);
		
		return head;
	} else {
		printf("\nList is empty\n");
		return head;
	}
}

Node* Reverse(Node *head){
	
	Node *current, *prev = NULL, *next;
	
	if(head != NULL){
		
		current = head;
		
		while(current != NULL){
		
			next = current->next;
			current->next = prev;
		
			prev = current;
			current = next;
		}
		
		head = prev;
		
		return head;
		
	} else {
		return head;
	}
}


Node* RemoveDuplicates(Node *head){
 
 	int currentData;
	Node * start, *temp;
	 
	if(head != NULL){
		
		start = head;
		
		currentData = start->data;
		
		while(currentData != start->next->data && start != NULL){
			start = start->next;
		}
		
		if(start->next->data == currentData){
			
			if(start->next == NULL){
				temp = head;
					
				while(temp->next->next != NULL){
					temp =  temp->next;
				}
					
				if(temp->next->next == NULL){
					temp->next = NULL;
				}
					
			} else {
				start->next = start->next->next;
			}
		}
	}
	 
	return head;
}


int GetNode(Node *head, int positionFromTail){
	
	int count = 0, ans, i=0;
	Node * start = head;
	
	if(head != NULL){
		while(head!=NULL){
			head = head->next;
			count += 1;
		}
	}
	
	ans = count - positionFromTail;
	while(i!=ans-1){
		start = start->next;
		i++;
	}
	return start->data; 
}


void ReversePrint(Node* head){
	
	if(head == NULL){
		return;
	} else {
		ReversePrint(head->next);
	}
	
	printf("%d\t", head->data);
}

void compare(){
	
	int value, res;
	Node *headA = NULL, *headB = NULL;
	
	while(1){
		printf("\nEnter the data in the first list - ");
		scanf("%d", &value);
		
		if(value == 0){
			break;
		} 
		
		headA = append(headA, value);
	}
	
	while(1){
		printf("\nEnter the data in the second list - ");
		scanf("%d", &value);
		
		if(value == 0){
			break;
		} 
		
		headB = append(headB, value);
	}
	
	printf("\nList - 1\n");
	printList(headA);
	
	printf("\nList - 2\n");
	printList(headB);
	
	
	res = CompareLists(headA, headB);
	printf("\n%d\n", res);
	if(res == 1){
		printf("\nLists are equal\n");
	} else {
		printf("\nLists are not equal\n");
	}
}


int CompareLists(Node* headA, Node* headB) {
	
	if(headA != NULL && headB != NULL){
		while(headA != NULL && headB != NULL){
			
			if(headA->data != headB->data){
				return 0;
			} 
			
			headA = headA->next;
			headB = headB->next;
		}
		
		if(headA != NULL || headB != NULL){
			return 0;
		} else {
			return 1;
		}	
	}
	
	if(headA != NULL || headB != NULL){
		return 0;
	}
	
	return 0; 
}



int main(){
	
	Node *head = init(head);
	int ch, value, total, pos, res;
		
	while(1){
		
		printf("\n1 - Insert data at the end");
		printf("\n2 - Insert data at the begining");
		printf("\n3 - Print the list");
		printf("\n4 - Count the number the list");
		printf("\n5 - Delete the data from the end");
		printf("\n6 - Delete the data from the first");
		printf("\n7 - Insert at postion");
		printf("\n8 - Delete at postion");
		printf("\n9 - Reverse the list");
		printf("\n10 - Print the list in reverse order");
		printf("\n11 - Compare the two list");
		printf("\n12 - Get the value[Enter the index it will display the data from the backward]");
		printf("\n13 - Remove duplicates");
		
		printf("\n\nEnter the option - ");
		scanf("%d", &ch);

		switch(ch){
			
			case 1: while(1){
						printf("\nEnter the data [Press 0 to terminate] - ");
						scanf("%d", &value);
						
						if(value == 0){
							break;
						} else {
							head = append(head, value);
						}
					}
			break;
			
			case 2: printf("\nEnter the data [Data will be added into the starting of the list] - ");		
					scanf("%d", &value);
					
					head = push(head, value);
			break;
			
			case 3: printList(head);
			break;
			
			case 4: total = getCount(head);
					printf("\nTotal data in the list is - %d", total);
			break;
			
			case 5: head = deleteFromLast(head);
					printList(head);
			break;
			
			case 6: head = deleteFromFirst(head);
					printList(head);
			break;
			
			case 7: printf("\nEnter the position - ");
					scanf("%d", &pos);
					
					printf("\nEnter the data - ");
					scanf("%d", &value);
	
					head = insertAtPosition(head, pos, value);	
			break;
			
			case 8: printf("\nEnter the position - ");
					scanf("%d", &pos);
					
					head = Delete(head, pos);
			break;
			
			case 9: head = Reverse(head);
					printList(head);
			break;
			
			case 10: ReversePrint(head);
			break;
			
			case 11: compare();
			break;
			
			case 12: printf("\nEnter the position - ");
					 scanf("%d", &pos);
					 value = GetNode(head, pos);
					 printf("%d", value);
			break;
			
			case 13: head = RemoveDuplicates(head);
			break;
			
			default: printf("\nERROR: Wrong input\n");
			break;						
		}
	}	
}
