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

void push(Node **head, int data){
	Node *temp = createNode(data);
	if((*head) == NULL){
		(*head) = temp;	
	} else {
		temp->next = (*head);
		(*head) = temp;
	}
}

void pop(Node **head){
	if((*head) != NULL){
		Node *temp = (*head);
		(*head) = temp->next;
		free(temp);
	}
}

int peek(Node *head){
	int data;
	if(head != NULL){
		data = head->data;
	}
	return data;
}

void insert(Node **head, Node **aux, int data){
	int x;
	push(head, data);
	if(aux == NULL){
		push(head, data);	
	} else {
		x = peek(*aux);
		if(x > data){
			push(aux, data);
		} else {
			push(aux, x);
		}
	}
}

void deleteNode(Node **head, Node **aux){
	pop(head);
	pop(aux);
}

void printStack(Node *head){
	if(head != NULL){
		while(head != NULL){
			cout << head->data <<" ";
			head = head->next;
		}
		cout << endl;
	}
}

int getMin(Node *head){
	return (head != NULL) ? head->data : 0;
}

int main(){
	
	int data;
	Node *head = NULL;
	Node *aux = NULL;
	
	while(1){
		cin >> data;
		if(data == 0){
			break;
		} else {
			insert(&head, &aux, data);
		}
	}
	
	printStack(head);
	printStack(aux);
	
	cout << "\nMin value - " << getMin(aux) << endl;
	
	deleteNode(&head, &aux);
	
	printStack(head);
	printStack(aux);
	
	cout << "\nMin value - " << getMin(aux) << endl;
	
	return 0;
}

