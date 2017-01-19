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
	return temp;
}

Node *insert(Node *head, int data){
	
	Node *temp = createNode(data);
	Node *current = head;
	
	if(head == NULL){
		temp->next = temp;
		head = temp;
	} else {
		while(current->next != head){
			current = current->next;
		}
		current->next = temp;
		temp->next = head;
	}
	return head;
}

void printList(Node *head){

	Node *current;
	
	if(head != NULL){
		current = head;
		do {
			cout << current->data <<" ";
			current = current->next;
		} while(current != head);
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
			head = insert(head, data);
		}
	}
	
	printList(head);
	return 0;
}










