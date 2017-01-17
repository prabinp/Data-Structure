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
	Node *start;
	
	if(head == NULL){
		head = temp;
	} else {
		start = head;
		while(start->next != NULL){
			start = start->next;
		}
		start->next = temp;
	}
	return head;
}

void swapNode(Node **head, int a, int b){
	
	if(a == b){
		return;
	}
	
	Node *currX = *head, *prevX = NULL;
	
	while(currX->data != a && currX->next != NULL){
		prevX = currX;
		currX = currX->next;
	}
	
	Node *currY = *head, *prevY = NULL;
	
	if(prevX != NULL){
		prevX->next = currY;
	} else {
		*head = currY;
	}
	
	if(prevY != NULL){
		prevY->next = currX;
	} else {
		*head = currX;
	}
	
	Node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
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

int main(){
	
	int data, a, b;
	Node *head = NULL;
	
	while(1){
		cin >> data;
		if(data == 0){
			break;
		} else {
			head = append(head, data);
		}
	}
	
	printList(head);
	
	cin >> a;
	cin >> b;
	
	swapNode(&head, a, b);
	printList(head);
	
	return 0;
}
