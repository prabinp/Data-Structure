#include<stdio.h>
#define SIZE 10

typedef struct ArrayBasedList {
	int size;
	int array[SIZE];
	int length;
} List;

void init(List *start){
	
	start->length = 0;
	start->size = SIZE;
	
	printf("\nInitialization done...\nSize of the list - %d\n\n",start->size);
}


void insert(List *start, int value) {
	
	start->array[start->length] = value;
	start->length++;
}


void display(List *start){
	int i=0;
	while(i != start->length){
		printf("\n%d",start->array[i]);
		i++;
	}
}


int search(List *start, int key){
	int i=0;
	if(start->length==0){
		return -1;
	} else {
		
		while(i != start->length){
			if(start->array[i]==key){
					return i;
			} else if(start->array[i]==start->length && start->array[i] != key){
					return -2;
			}
			i++;
		}		
	}
}
