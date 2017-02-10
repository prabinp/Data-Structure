#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct stack {
	int top;
	int capacity;
	char *arr;
} Stack;

Stack *createStack(int capacity){
	Stack *stack = (Stack *) malloc(sizeof(Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->arr = (char *) malloc(stack->capacity * sizeof(char));
	return stack;
}

int isEmpty(Stack *stack){
	int res = ((stack->top == -1) ? 1 : 0);
	return res;
}

int isFull(Stack *stack){
	int res = ((stack->top == stack->capacity-1) ? 1 : 0);
	return res;
}

char peek(Stack *stack){
	return stack->arr[stack->top];
}

void push(Stack *stack, char op){
	if(!isFull(stack)){
		stack->arr[++stack->top] = op;
	}
}

char pop(Stack *stack){
	char op;
	if(!isEmpty(stack)) {
		op = stack->arr[stack->top];
		stack->top--;
	}
	return op;
}

void reverseTheString(char *str){
	
	Stack *stack = createStack(strlen(str));
	
	for(int i=0; str[i]; i++){
		push(stack, str[i]);
	}
	
	for(int i=0; str[i]; i++){
		str[i] = pop(stack);
	}
}

int main(){
	
	char str[20];
	
	cout <<"\nEnter the string - ";
	cin.read(str, 7);
	
	reverseTheString(str);
	
	for(int i=0; str[i]; i++){
		cout << str[i];
	}
	return 0;
}

