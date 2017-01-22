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

void printList(Node *head){
	if(head != NULL){
		while(head != NULL){
			cout << head->data <<" ";
			head = head->next;
		}	
	}
}

Node *detectLoop(Node *head){
	
	Node *fast = head, *slow = head;
	
	while(slow != NULL && fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			slow->next = NULL;
		}
	}
	return head;
}

int main(){
	
	Node *head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	
	head->next->next->next->next->next = head->next;
	
	head = detectLoop(head);
	printList(head);
	
	return 0;
}


