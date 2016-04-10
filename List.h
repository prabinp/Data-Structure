/*
 * This header file contain the function of basic operations add this header into the program and 
   perform the operations as required.
 */

#include<stdio.h>
#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct ArrayBasedList {
	int size;
	int array[SIZE];
	int length;
} List;


int isFull(List *start){
	if(start->length == start->size){
		return 	TRUE;
	} else {
		return FALSE;
	}
}


int isEmpty(List *start){
	if(start->length == 0){
		return TRUE;
	} else {
		return FALSE;
	}
}


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
		printf("  %d",start->array[i]);
		i++;
	}
	printf("\nList length is %d\n",start->length);
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
	return -1;
}


int insertAtBeg(List *start, int key){
	int i;
		for(i = start->length; i>0; i--){
			start->array[i] = start->array[i-1];
		}
		start->array[0] = key;
		start->length++;
		
		return 1;
}


int insertAtPos(List *start, int key, int pos){
	int i, space;
		if(pos > start->size){
			printf("\nERROR: Invalid position\n");
		} else {
			for(i = start->length; i > pos; i--){
				start->array[i] = start->array[i-1];
			}
			start->array[pos] = key;
			start->length++;
			
			return 1;
		}
	return -1;
}


int removeAtPos(List *start, int key){
	int i;
	if(key > start->length){
		printf("\nERROR: Invalid position\n");
	}
	else {
		for(i = key-1; i < start->length; i++){
			start->array[i] = start->array[i+1];
		}
		start->length--;
		return 1;
	}
	return -1;
}


int removeAtBeg(List *start){
	int i;
	for(i = 0; i < start->length; i++){
		start->array[i] = start->array[i+1];
	}
	start->length--;
	return 1;
}

int removeFromEnd(List *start){
	start->length--;
	return 1;
}

void sortList(List *start){
	int i, c, temp;
	for(i =0; i<start->length; i++){
		c = i;
		while(c > 0 && start->array[c] < start->array[c-1]){
			temp = start->array[c];
			start->array[c] = start->array[c-1];
			start->array[c-1] = temp;
			c--;
 		}
	}
	display(start);
}
