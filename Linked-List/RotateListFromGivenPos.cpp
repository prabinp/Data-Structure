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

Node *rotateListFromGivenPos(Node *head, int pos){
	
	int count = 1;
	Node *current = head, *temp, *prev = NULL, *next = NULL;
	
	
	if(head == NULL || count == 0 || head->next == NULL){
		return head;
	} else {
		while(count <= pos && current != NULL){
			if(prev == NULL){
				temp = prev = createNode(current->data);
			} else {
				temp->next = createNode(current->data);
				temp = temp->next;
			}
			current = current->next;
			count++;
		}
		temp = current;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = prev;
	}
	return current;
}

int main(){

	int data, pos;
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
	cin >> pos;
	
	head = rotateListFromGivenPos(head, pos);
	printList(head);
	return 0;
}

