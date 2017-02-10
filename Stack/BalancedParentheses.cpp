#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct stack {
	int top;
	int capacity;
	char *array;
} Stack;

Stack *init(int capacity){
	
	Stack *stack = (Stack *) malloc(sizeof(Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (char *) malloc(stack->capacity * sizeof(stack));
	
	return stack;
}

int isFull(Stack *stack){
	if(stack->top == stack->capacity){
		return 1;
	} else {
		return 0;
	}
}

int isEmpty(Stack *stack){
	if(stack->top == -1){
		return 1;
	} else {
		return 0;
	}
}

Stack *push(Stack *stack, char data){
	if(isFull(stack)){
		printf("\nStack is full\n");
	} else {
		stack->top++;
		stack->array[stack->top] = data;
	}
	
	return stack;
}

char pop(Stack *stack){
	char data;
	if(isEmpty(stack)){
		printf("\nStack is empty\n");
	} else {
		data = stack->array[stack->top];
		stack->top--;
	}
	return data;
}

char peek(Stack *stack){
	return stack->array[stack->top];
}

int isMatchingPair(char data1, char data2){
	if(data1 == '(' && data2 == ')'){
		return 1;
	} else if(data1 == '{' && data2 == '}'){
		return 1;
	} else if(data1 == '[' && data2 == ']'){
		return 1;
	} else {
		return 0;
	}
}

void checkBalancedParentheses(int m, int n, char arr[][n]){
	
	Stack *stack;
	
	for(int j=0; j<m; j++){
		
		stack = init(n);
	
		for(int i=0; arr[j][i] != '\0'; i++){
			if(arr[i]=='(' || arr[i]=='{' || arr[i]=='['){
				stack = push(stack, arr[i]);
			} else if(arr[i]==')' || arr[i]=='}' || arr[i]==']'){
				 if(isMatchingPair(pop(stack),arr[i])==0) {
					cout << "\nNo";
					break;
				}
			}
		}
		
		if(isEmpty(stack)){
			cout << "\nYes";
		} else {
			cout << "\nNo";
		}
	}	
}

int main(){
	
	int test, d = 1000;
	
	cin >> test;
	
	char arr[test][d];
	
	for(int i=0; i<test; i++){
		cin >> arr[i];
	}
	
	checkBalancedParentheses(test, d, arr);
	
	return 0;
}
