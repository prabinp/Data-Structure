#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
} Node;

Node *createNode(int data){
	Node *temp = (Node *) malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int isEmpty(Node *head){
	if(head == NULL) {
		return 1;	
	} else {
		return 0;	
	}
}

Node *push(Node *head, int data){
	
	Node *temp = createNode(data);
	if(isEmpty(head)){
		head = temp;
	} else {
		temp->next = head;
		head = temp;
	}
	return head;
}

int pop(Node **head){
	
	Node *temp;
	
	int data;
	if(!isEmpty(*head)){
		temp = (*head);
		(*head) = temp->next;
		
		data = temp->data;
		free(temp);
	}
	
	return data;
}

int peek(Node *head){
	return head->data;
}

Node *sortedInserted(Node *head, int data){
	
	if(isEmpty(head) || data > peek(head)){
		head = push(head, data);
	} else {
		int temp = pop(&head);
		head = sortedInserted(head, data);
		head = push(head, temp);
	}
	return head;
}

Node *sortStack(Node *head){
	
	int data;
	if(!isEmpty(head)){
		data = pop(&head);
		head = sortedInserted(head, data);
	}
	return head;
}

void printStack(Node *head) {
	if(!isEmpty(head)){
		while(head!= NULL){
			cout << head->data <<" ";
			head = head->next;
		}
	}
	cout << endl;
}

int main(){
	
	Node *head = NULL;
	int data;
	
	while(1){
		cout << "\nEnter the data - ";
		cin >>  data;
		
		if(data == 0){
			break;
		} else {
			head = push(head, data);
		}
	}
	
	printStack(head);
	
	head = sortStack(head);
	printStack(head);
	
	return 0;
}
