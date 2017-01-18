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

Node *sortedMerge(Node *a, Node *b){
	
	Node *head = NULL, *temp = NULL;
	
	while(a != NULL && b != NULL){
		if(a->data <= b->data){
			if(head == NULL){
				temp = head = createNode(a->data);
			} else {
				temp->next = createNode(a->data);
				temp = temp->next;
			}
			a = a->next;
		} else {
			if(head == NULL){
				temp = head = createNode(b->data);
			} else {
				temp->next = createNode(b->data);
				temp = temp->next;
			}
			b = b->next;
		}
	}
		
	while(a != NULL){
		temp->next = createNode(a->data);
		temp = temp->next;
		a = a->next;
	}
		
	while(b != NULL){
		temp->next = createNode(b->data);
		temp = temp->next;
		b = b->next;
	}
	return head;
}

void splite(Node *head, Node **front, Node **back){
	
	Node *fast;
	Node *slow;
	
	if(head == NULL || head->next == NULL){
		*front = head;
		*back = NULL;
	} else {
		slow = head;
		fast = head->next;
		
		while(fast != NULL){
			fast = fast->next;
			if(fast != NULL){
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

void mergeSort(Node **head){
	
	Node *current = *head;
	Node *a, *b;
	
	if(current == NULL || current->next == NULL){
		return;
	} else {
		splite(current, &a, &b);
		mergeSort(&a);
		mergeSort(&b);
		*head = sortedMerge(a, b);
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
			head = append(head, data);
		}
	}
	
	printList(head);
	mergeSort(&head);
	
	printList(head);
	return 0;
}
