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

int isOperand(char ch){
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int prec(char op){
	switch(op){
		case '+' : 
		case '-' : 
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;		
	}
	return -1;
}

int infixToPostfix(char *exp){
	
	Stack *stack = createStack(strlen(exp));
	int k = -1;
	for(int i = 0; exp[i]; i++){
		if(isOperand(exp[i])){
			exp[++k] = exp[i];
		} else if(exp[i] == '('){
			push(stack, exp[i]);
		} else if(exp[i] == ')'){
			while(!isEmpty(stack) && peek(stack) != '('){
				exp[++k] = pop(stack);
			}
			pop(stack);	
		} else {
			while(!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack))){
				exp[++k] = pop(stack);
			}
			push(stack, exp[i]);
		}
	}
	
	while(!isEmpty(stack)){
        exp[++k] = pop(stack );
	}
}

int main(){
	
	char exp[20];
	
	cout <<"\nEnter the experiance - ";
	cin.read(exp, 20);
	
	infixToPostfix(exp);
	
	for(int i=0; exp[i]; i++){
		cout << exp[i] <<" ";
	}
	return 0;
}

