#include<stdio.h>
#include<stdlib.h>

typedef struct arraylist{
	int capacity;
	int *arr;
	int length;
} ArrayList;

ArrayList *init(int capacity){

	ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
	list->capacity = capacity;
	list->arr = (int *)	malloc(list->capacity * sizeof(int));
	list->length = -1;
	return list;
}

int isEmpty(ArrayList *list){		
	//return list->length == -1;
	if(list->length == -1){
		return 1;
	} else {
		return 0;
	}
}

int isFull(ArrayList *list){
	if(list->length == list->capacity-1){
		return 1;
	} else {
		return 0;
	}
}

/* This function is used to find out weather the given position of element is avalible or not */
int isAvalible(ArrayList *list, int pos){
	
	if(pos >= 0 && pos <= list->length || pos == list->length+1){
		return 1;
	} else {
		return 0;
	}
}

void insert(ArrayList *list, int data, int position){
	
	int i=0;
	if(isFull(list)){
		printf("\nList is full\n");
	} else {
		i = list->length;
		while(i >= position){
			list->arr[i+1] = list->arr[i];
			i--;
		}
		list->arr[i+1] = data;
		list->length++;
	}
}

int elementAt(ArrayList *list, int *data, int pos){
	if(isEmpty(list)){
		return 0;
	} else {
		if(pos > list->length){
			return -2;
		} else {
			*data = list->arr[pos];
			return 1;	
		}
	}
}

int search(ArrayList *list, int data){
	
	int i;
	if(isEmpty(list)){
		return -2;
	} else {
		i=0;
		while(i<=list->length && list->arr[i] != data){
			i++;
		}
		if(list->arr[i] == data){
			return i;
		} else {
			return -1;
		}
	}
}

void printList(ArrayList *list){
	int i;
	if(!isEmpty(list)){
		for(i = 0; i<=list->length; i++){
			printf("%d ", list->arr[i]);
		}	
	}
}

int deleteElement(ArrayList *list, int position, int *data){
	
	int i;
	
	if(isEmpty(list)){
		return -1;
	} else {		
		if(position >= 0 && position <= list->length){
			i = position;
			*data = list->arr[position];
			while(i < list->length){
				list->arr[i] = list->arr[i+1];
				i++;
			}
			list->length--;
			return 1;
		} else {
			return -2;
		}	
	}
}

void sort(ArrayList *list){
	
	int i, j, temp;
	
	for(i=0; i<list->length; i++){
			j=i;		
			while(j>0 && list->arr[j] < list->arr[j-1]){
				temp = list->arr[j];
				list->arr[j] = list->arr[j-1];
				list->arr[j-1] = temp;
				j--;
			}
	}
}

void expandList(ArrayList *list){
	
	int space, i=0;
	ArrayList *newList;
	
	if(!isFull(list)){
		space = (list->capacity-1) - list->length;
		printf("\nYou still have %d spaces left\n", space);
	} else if(isEmpty(list)){
		printf("\nYou haven't use the list yet\n");
	} else {
		space = list->capacity / 2;
		
		printf("\nOld capacity - %d / 2 = %d\n", list->capacity, space);
		space += list->capacity;
		
		printf("\nNew capacity - %d\n", space);
		
		list->arr = (int *) realloc(list->arr, space);
		list->capacity = space;
	
		printf("\nCopy data to the new list successfull\n");
	}
}

void mergeAt(ArrayList *dest, ArrayList *sour, int pos){
	int i, j, newPos, displacement;
		
	if(i > dest->length){
		printf("\nCan not merge from the given position\n");
	} else if(i < dest->length){
			
		dest->arr = (int *) realloc(dest->arr, dest->capacity + sour->capacity);
		newPos = (sour->length+1) + pos;
		
		for(i=pos; i<=dest->length; i++){
			dest->arr[newPos] = dest->arr[i];
			newPos++;
		}
		
		j=pos;
		for(i=0; i<=sour->length; i++){
			dest->arr[j] = sour->arr[i];
			j++;
		}
	} else if(i < dest->length+1){
		
		for(i=0; i<=sour->length; i++){
			dest->length++;
			dest->arr[dest->length] = sour->arr[i];	
		} 
	}
	
	dest->length += sour->length + 1;
}

void subList(ArrayList *list, int start, int end){
	
	int i;
	
	if(start > end){
		printf("\nCan not perform the operation\n");
	} else {
		for(i=start; i<end; i++){
			printf("%d ", list->arr[i]);
		}
	}
}


