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

Node *push(Node *head, int data){
	
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

void spliteList(Node *head, Node **head1, Node **head2){
	
	Node *fast = head;
	Node *slow = head;
	
	while(fast->next != head && fast->next->next != head){
		fast = fast->next;
		slow = slow->next;
	}
	
	if(fast->next->next == head){
		fast = fast->next;
	}
	
	*head1 = head;
	
	if(head->next != head){
		*head2 = slow->next;
	}
	
	fast->next = slow->next;
	slow->next = head;
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
	cout << endl;
}

int main(){
	
	int data;
	Node *head = NULL, *head1 = NULL, *head2 = NULL;
	
	while(1){
		cout <<"\nEnter the data - ";
		cin >> data;
		if(data == 0){
			break;
		} else {
			head = push(head, data);
		}
	}
	
	spliteList(head, &head1, &head2);
	printList(head1);
	printList(head2);
	
	return 0;
}
