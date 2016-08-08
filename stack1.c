#include<stdio.h>
#include<stdlib.h>


typedef struct stack {
	int top;
	int *a;
	int capacity;
} Stack;

Stack *init(Stack *stack, int capacity){
	
	stack = (Stack *) malloc(sizeof(Stack));
	stack->capacity = capacity;
	
	stack->a = (int *) malloc(stack->capacity * sizeof(int));
	stack->top = -1;
	
	return stack;
}

int isEmpty(Stack *stack){
	if(stack->top == -1){
		return 1;
	} else {
		return -1;
	}
}

int isFull(Stack *stack){
	if(stack->top == stack->capacity){
		return 1;
	} else {
		return -1;
	}
}

Stack *push(Stack *stack, int value){
	
	if(isFull(stack) == -1){
		stack->top++;
		stack->a[stack->top] = value;
	} else {
		printf("\nStack is full\n");
	}
	
	return stack;
}

int peek(Stack *stack){

	if(isEmpty(stack) == 1){
		printf("\nStack is empty\n");
		return;
	} else {
		return stack->a[stack->top];
	}
}

int pop(Stack *stack){
	
	int value;
	if(isEmpty(stack) == -1){
		value = stack->a[stack->top];
		stack->top--;
		return value;
	} else {
		printf("\nStack is empty\n");
		return;
	}
}

void printStack(Stack *stack){
	int i;
	for(i=stack->top; i>=0; i--){
		printf("%d\t", stack->a[i]);
	}
}

int main(){
	
	int ch, value;
	Stack *stack;
	
	printf("\nEnter the size of the stack - ");
	scanf("%d", &value);
	
	stack = init(stack, value-1);
	
	printf("\nStack is initialized to %d\n", value);
	
	while(1) {
	
		printf("\n1 - insert he elements");
		printf("\n2 - display");
		printf("\n3 - check the peek");
		printf("\n4 - pop the elements");
		
		printf("\n\nEnter the option - ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1: printf("\nEnter the data - ");
					scanf("%d", &value);
					stack = push(stack, value);
			break;
			
			case 2: printStack(stack);
			break;
			
			case 3: value = peek(stack);
					printf("\n%d\n", value);
			break;
			
			case 4: value = pop(stack);
					printf("\n%d\n", value);
			break;		
			
			default: printf("\nERROR: Wrong input\n");
			break; 
		}
	}
	
	return 0;
}
