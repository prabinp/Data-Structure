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

bool isEmpty(Node *head){
	bool flag = (head == NULL) ? true : false;
	return flag;
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
	if(!isEmpty(head)){
		return head->data;
	}
}

void sortedInserted(Node **head, int x){
	if((*head) == NULL || x > peek(*head)){
		push(head, x);
		return;
	} else {
		int temp = pop(head);
		sortedInserted(head, x);
		push(head, temp);
	}
}

void popAll(Node **head){
	if(!isEmpty(*head)){
		int x = pop(head);
		popAll(head);
		sortedInserted(head, x);
	}
}

void printStack(Node *head){
	if(!isEmpty(head)){
		while(head != NULL){
			cout << head->data <<" ";
			head = head->next;
		}
		cout << endl;
	}
}

int main(){
	int data;
	Node *head = NULL;
	
	while(1){
		cout << "\nEnter the data - ";
		cin >> data;
		if(data == 0){
			break;
		} else {
			push(&head, data);
		}
	}
	
	printStack(head);
	popAll(&head);
	printStack(head);
	
	return 0;
}
