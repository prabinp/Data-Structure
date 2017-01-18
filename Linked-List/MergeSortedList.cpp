#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *createNode(int data){
	Node *temp = (Node *) malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

Node *insert(Node *head, int data){
	Node *temp = createNode(data);
	if(head == NULL){
		head = temp;
	} else {
		head->next = insert(head->next, data);
	}
	return head;
}

void printList(Node *head){
	if(head != NULL){
		cout << head->data <<" ";
		printList(head->next);
	}
}

Node *mergeList(Node *a, Node *b){
	
	Node *result = NULL, *temp = NULL;
	
	while(a != NULL && b != NULL){
		if(a->data <= b->data){
			if(result == NULL){
				temp = result = createNode(a->data);
			} else {
				temp->next = createNode(a->data);
				temp = temp->next;
			}
			a = a->next;
		} else {
			if(result == NULL){
				temp = result = createNode(b->data);
			} else {
				temp->next = createNode(b->data);
				temp = temp->next;
			}
			b = b->next;
		}
	}
	
	while(a != NULL){
		temp->next = createNode(a->data);
		a = a->next;
		temp = temp->next;
	}
	
	while(b != NULL){
		temp->next = createNode(b->data);
		b = b->next;
		temp = temp->next;
	}
	return result;
}

int main(){
	
	int value, first, second;

	Node *head = NULL, *result = NULL, *head2 = NULL;
	
	while(1){
		cout << "\nEnter the data - ";
		cin >> value;
		if(value != 0){
			head = insert(head, value);
		} else {
			break;
		}
	}

	while(1){
		cout << "\nEnter the data - ";
		cin >> value;
		if(value != 0){
			head2 = insert(head2, value);
		} else {
			break;
		}
	}
	
	result = mergeList(head,head2);
	
	printList(result);
	return 0;
}
