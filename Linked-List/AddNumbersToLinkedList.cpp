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
		temp->next = head;
		head = temp;
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
}

Node *numberToList(Node *head, int number){
	
	int digit;
	while(number > 0){
		digit = number % 10;
		number /= 10;
		head = append(head, digit); 
	}
	return head;
}

int main(){
	
	Node *head = NULL;
	int number;
	
	cout << "Enter the number - ";
	cin >> number;
	head = numberToList(head, number);
	
	printList(head);
	return 0;
}
