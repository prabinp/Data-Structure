#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct stack {
	char data;
	struct stack *next; 
} Stack;

Stack *createNode(char data){
	Stack *temp = (Stack *) malloc(sizeof(Stack));
	temp->data = data;
	temp->next = NULL;
	
	return temp;
}

void push(Stack **stack, char data){
	Stack *newNode = createNode(data);
	if(*stack == NULL){
		*stack = newNode;
	} else {
		newNode->next = (*stack);
		(*stack) = newNode;
	}
}

char pop(Stack **stack){
	
	char data = 'o';
	Stack *temp;
	
	if(stack == NULL){
		return data;
	} else {
		temp = *stack;
		data = temp->data;
		*stack = temp->next;
		free(temp);
		return data;
	}
}

int isMatchingPair(char c1, char c2){
	if(c1 == '(' && c2 == ')'){
		return 1;
	} else if(c1 == '{' && c2 == '}'){
		return 1;
	} else if(c1 == '[' && c2 == ']'){
		return 1;
	} else {
		return 0;
	} 
}

int areBalacedParentes(char exp[]){
	int i=0;
	
	Stack *stack = NULL;
	
	while(exp[i]){
		 if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
		 	push(&stack, exp[i]);
		 } else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
		 	if(stack == NULL){
		 		return 0;
			} else if(isMatchingPair(pop(&stack), exp[i]) == 0) {
				return 0;
			}
		 }
		 i++;
	}
	if(stack == NULL){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	
	int test;
	cin >> test;
	
	char arr[10000];
	
	for(int i=0; i<test; i++){
		cin >> arr;
		if(areBalacedParentes(arr) == 1){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}	
	return 0;
}
