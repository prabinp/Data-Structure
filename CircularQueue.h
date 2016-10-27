#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int front;
	int rear;
	int *arr;
	int capacity;
} Queue;

Queue *init(int capacity){

	Queue *list = (Queue *) malloc(sizeof(Queue));
	list->capacity = capacity+1;
	list->arr = (int *)	malloc(list->capacity * sizeof(int));
	list->rear = -1;
	list->front = 0;
	return list;
}

int isEmpty(Queue *queue){		
	if(((queue->rear+1)%queue->capacity) < queue->front){
		return 1;
	} else {
		return 0;
	}
}

int isFull(Queue *queue){
	if(((queue->rear+2)%queue->capacity) == queue->front){
		return 1;
	} else {
		return 0;
	}
}

void insert(Queue *queue, int data){
	if(isFull(queue)){
		printf("\nList is full\n");
	} else {
		queue->rear = (queue->rear+1) % queue->capacity;
		queue->arr[queue->rear] = data;
	}
}

void print(Queue *queue){
	int i;
	if(isEmpty(queue)){
		printf("\nQueue is empty\n");
	}
	else {
		i = queue->front;
		while(i<=queue->rear){
			printf("%d ", queue->arr[i]);
			i++;
		}
	}
}

void deleteItem(Queue *queue, int *data){
	if(isEmpty(queue)){
		printf("\nQueue is empty\n");
	} else {
		*data = queue->arr[queue->front];
		queue->front = (queue->front + 1) % queue->capacity; 
	}
} 
