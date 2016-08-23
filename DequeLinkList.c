#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int data;
	struct queue *next;
} Queue;

Queue *init(Queue *queue){
	return queue = NULL; 
}

Queue *insertFront(Queue *queue, int data){
	
	Queue *start;
	Queue *temp = (Queue *) malloc(sizeof(Queue));

	temp->data = data;
	temp->next = NULL;
	
	if(queue==NULL){
		queue = temp;
	} else {
		start = queue;
		
		while(start->next != NULL){
			start = start->next;
		}
		
		start->next = temp;
		start = temp;
	}
	
	return queue;
}

Queue *insertRear(Queue *queue, int data){
	
	Queue *temp = (Queue *) malloc(sizeof(Queue));

	temp->data = data;
	temp->next = NULL;
	
	if(queue==NULL){
		queue = temp;
	} else {
		temp->next = queue;
		queue = temp;
	}
	
	return queue;
}

Queue *deleteFront(Queue *queue){
	
	Queue *temp;
	if(queue == NULL){
		printf("\nQueue is empty\n");
	} else if(queue->next == NULL){
		queue = NULL;
	} else {
		
		temp = queue;
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		
		if(temp->next->next == NULL){
			temp->next = NULL;
		}
	}
	
	return queue;
}

Queue *deleteRear(Queue *queue){
	Queue *temp;
	
	if(queue != NULL){
		temp = queue;
		queue = queue->next;
		free(temp);
	} else {
		printf("\nQueue is empty\n");
	}
	
	return queue;
}

int getFront(Queue *queue){
	
	Queue *temp;
	if(queue==NULL){
		printf("\nQueue is empty\n");
		return 0;
	} else {
		temp = queue;
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		return temp->data;
	}
}

int getRear(Queue *queue){
	
	if(queue==NULL){
		printf("\nQueue is empty\n");
		return 0;
	} else {
		return queue->data;
	}
}

void printQueue(Queue *queue){
	
	if(queue==NULL){
		printf("\nQueue is empty\n");
	} else {
		while(queue != NULL){
			printf("%d ", queue->data);
			queue = queue->next;
		}
		printf("\n");
	}
}

int main(){
	
	int ch, value;
	Queue *queue = init(queue);
	
	while(1){
	
		printf("\n1 - insert at front");
		printf("\n2 - insert at rear");
		printf("\n3 - delete front");
		printf("\n4 - delete rear");
		printf("\n5 - get the front");
		printf("\n6 - get the rear");
		printf("\n7 - print the queue");
		
		printf("\n\nEnter the option - ");
		scanf("%d", &ch);
			
		switch(ch){
			case 1: printf("\nEnter the data - ");
					scanf("%d", &value);	
					queue = insertFront(queue, value);
			break;
			
			case 2: printf("\nEnter the data - ");
					scanf("%d", &value);	
					queue = insertRear(queue, value);
			break;
			
			case 3: queue = deleteFront(queue);
			break;
			
			case 4: queue = deleteRear(queue);
			break;
			
			case 5: printf("\n%d\n", getFront(queue));
			break;
			
			case 6: printf("\n%d\n", getRear(queue));
			break;
			
			case 7: printQueue(queue);
			break;
			
			default: printf("\nERROR: Wrong input\n");
			break;		
		}
	}
	
	return 0;
}
