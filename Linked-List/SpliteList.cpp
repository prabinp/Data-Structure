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
		head->next = append(head->next, data);
	}
	return head;
}

void printList(Node *head){
	if(head != NULL){
		cout << head->data <<" ";
		printList(head->next);
	}
	cout << endl;
}

void splite(Node *head, Node **a, Node **b){
	
	Node *fast = head;
	Node *slow = head;
	*a = slow;
		
	while(fast->next != NULL){
		fast = fast->next;
		if(fast->next != NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	*b = slow->next;
	slow->next = NULL;
}

int main(){
	
	int data;
	Node *head = NULL, *list1, *list2;
	
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
	splite(head, &list1, &list2);
	
	printList(list1);
	printList(list2);
	
	return 0;
}

