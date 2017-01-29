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

Node *append(Node *head, int data){
	
	Node *temp = createNode(data);
	
	if(head == NULL){
		head = temp;
	} else {
		head->next = append(head->next, data);
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

Node *reverseOfAGivenSize(Node *head, int size){
	
	Node *prev = NULL, *next, *last;
	Node *current = head;
	int count = 1;
	
	if(head == NULL || size == 0 || size == 1){
		return head;
	} else {
		while(count <= size && current != NULL){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
			count++;
		}
		last = prev;
		while(last->next != NULL){
			last = last->next;
		}
		last->next = current;
	}
	return prev;
}

int main(){

	int data, size;
	Node *head = NULL;
	
	while(1){
		cout << "\nEnter the data - ";
		cin >> data;
		if(data == 0){
			break;
		} else {
			head = append(head, data);
		}
	}
	
	printList(head);
	
	cout << "\nEnter the size - ";
	cin >> size;
	
	head = reverseOfAGivenSize(head, size);
	printList(head);
	
	return 0;
}
