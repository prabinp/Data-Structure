#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int front, rear, size;
	int capacity;
	int *array;
} Queue;

Queue *create(int capacity){
	
	Queue *queue = (Queue *) malloc(sizeof(Queue));
	queue->front = -1;
	queue->rear = 0;
	queue->size = 0;
	queue->capacity = capacity;
	queue->array = (int *) malloc(queue->capacity * sizeof(Queue));
	
	return queue;
}

int isFull(Queue *queue){
	if(queue->front == queue->capacity){
		return 1;
	} else {
		return 0;
	}
}

int isEmpty(Queue *queue){
	if(queue->front == -1){
		return 1;
	} else {
		return 0;
	}
}

Queue *push(Queue *queue, int data){
	if(isFull(queue)){
		printf("\nQueue is full\n");
	} else {
		queue->front++;
		queue->array[queue->front] = data;
		queue->size++;
	}
	
	return queue;
}

void pop(Queue *queue){
	if(isEmpty(queue)){
		printf("\nQueue is empty\n");
	} else if(queue->rear == queue->front) {
		printf("\nQueue is empty\n");
	} else {
		queue->array[queue->rear++];
		queue->size--;
	}
}

void printQueue(Queue *queue){
	int i;
	for(i=queue->rear; i<=queue->front; i++){
		printf("%d ", queue->array[i]);
	}
}

int main(){
	
	int value, ch;
	Queue *queue;
	
	printf("\nEnter the size of the queue - ");
	scanf("%d", &value);
	
	queue = create(value);
	printf("\nQueue is initallized with %d\n", value);
	
	while(1){
		printf("\n1 - insert in the data");
		printf("\n2 - remove the data");
		printf("\n3 - display the queue");
		
		printf("\n Enter the option - ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1: printf("\nEnter the data - ");
					scanf("%d", &value);
					
					queue = push(queue, value);
			break;
			
			case 2: pop(queue);
			break;
			
			case 3: printQueue(queue);
			break;
			
			default: printf("\nERROR: Wrong output\n");
			break;		
		}
	}
	
	return 0;
}
