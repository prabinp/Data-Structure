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

Node *append(Node *head, int data){
	Node *temp = createNode(data);
	Node *current = head;
	
	if(head == NULL){
		head = temp;
	} else {
		current = head;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = temp;
	}
	return head;
}

void printList(Node *head){
	if(head != NULL){
		while(head != NULL){
			cout << head->data <<" ";
			head = head->next;
		}
	}
	cout << endl;
}

void reverseList(Node **head){
	
	Node *prev = NULL;
	Node *current = *head, *next;
	
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int main(){
	
	int data;
	Node *head = NULL;
	
	while(1){
		cout <<"\nEnter the data - ";
		cin >> data;
		if(data == 0){
			break;
		} else {
			head = append(head, data);
		}
	}
	
	printList(head);
	reverseList(&head);
	printList(head);
	
	return 0;
}

