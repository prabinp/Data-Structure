#include<stdio.h>
#include"CircularQueue.h"

int main(){
	
	int value, ch, data;
	Queue *queue;
	
	printf("\nEnter the size of the queue - ");
	scanf("%d", &value);
	
	queue = init(value);
	
	while(1){
		printf("\n1 - Insert");
		printf("\n2 - Print");
		printf("\n3 - Remove");
		
		printf("\n\nEnter the option - ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1: printf("\nEnter the value - ");
					scanf("%d", &value);
					insert(queue, value);
			break;
			
			case 2: print(queue);
			break;
			
			case 3:	deleteItem(queue, &data);
					printf("\n%d\n", data);
			break;			
		}
	}

	return 0;
}
