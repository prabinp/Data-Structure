#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
using namespace std;

typedef struct stack{
	int top;
	int capacity;
	int *arr;
} Stack;

Stack *createStack(int capacity){
	Stack *stack = (Stack *) malloc(sizeof(Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->arr = (int *) malloc(stack->capacity * sizeof(int));
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

int peek(Stack *stack){
	return stack->arr[stack->top];
}

void push(Stack *stack, char op){
	if(!isFull(stack)){
		stack->arr[++stack->top] = op;
	}
}

int pop(Stack *stack){
	int op;
	if(!isEmpty(stack)) {
		op = stack->arr[stack->top];
		stack->top--;
	}
	return op;
}

int evaluationOfPostfix(char *exp){
	
	Stack *stack = createStack(strlen(exp));
	
	for(int i=0; exp[i]; i++){
		if(isdigit(exp[i])){
			push(stack, exp[i] - '0');
		} else {
			int val1 = pop(stack);
			int val2 = pop(stack);
			int ans;
			
			switch(exp[i]){				
				case '+' : ans = val1 + val2;
						   push(stack, ans);
				break;
				
				case '-' : ans = val1 - val2;
						   push(stack, ans);
				break;
				
				case '*' : ans = val1 * val2;
						   push(stack, ans);
				break;
				
				case '/' : ans = val1 / val2;
						   push(stack, ans);
				break;		   		   
			}
		}
	}
	return pop(stack);
}

int main(){
	
	char exp[20];
	
	cout <<"\nEnter the experiance - ";
	cin.read(exp, 3);
	
	cout << "Ans - " << evaluationOfPostfix(exp);
	
	return 0;
}

