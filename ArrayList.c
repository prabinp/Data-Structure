#include<stdio.h>
#include"..\\List\\List.h"

int main(){
	
	int size, i, data, ch, pos, ack, start, end;
	ArrayList *list, *list2;
	
	printf("\nEnter the size of the list - ");
	scanf("%d", &size);
	
	list = init(size);
	
	while(1){
		printf("\n1 - Append");
		printf("\n2 - Print list");
		printf("\n3 - Insert at begining");
		printf("\n4 - Insert at position");
		printf("\n5 - Length of the list");
		printf("\n6 - Sort the list");
		printf("\n7 - Search an element");
		printf("\n8 - Delete from last");
		printf("\n9 - Delete from first");
		printf("\n10 - Delete from position");
		printf("\n11 - Expend the list");
		printf("\n12 - Merge the list");
		printf("\n13 - Sublist");
		
		printf("\n\nEnter the option - ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1: /* Append */
			
				if(isFull(list)){
					printf("\nList is full\n");
				} else {
					printf("\nEnter the data - ");
					scanf("%d", &data);
					pos = list->length+1;
					insert(list, data, pos);
				}		
			break;
			
			case 2: /* Print list */ 
			
				printList(list);
			break;
			
			case 3: /* Insert at begining */
			
				if(!isFull(list)){
					pos = 0;
					printf("\nEnter the data - ");
					scanf("%d", &data);
					insert(list, data, pos);
						
				} else {
					printf("\nList is full\n");
				}	
			break;
			
			case 4:	/* Insert at position */
			
				if(!isFull(list)){
				
					printf("\nEnter the position - ");
					scanf("%d", &pos);
						
					if(!isAvalible(list, pos)){
						printf("\nPosition  %d is wrong. Inserting at %d\n", pos, list->length+1);
						pos = list->length+1;
					}
					printf("\nEnter the data - ");
					scanf("%d", &data);
					insert(list, data, pos);
				}
			break;
			
			case 5: /* Length of the list */ 
			
				printf("\nLength of the list - %d\n", list->length);
			break;
			
			case 6: /* Sort the list */
			
				sort(list);
			break;
			
			case 7: /* Search an element */
			
				printf("\nEnter the data - ");
				scanf("%d", &data);
					
				ack = search(list, data);
				if(ack == -2){
					printf("\nList is empty\n");
				} else if(ack == -1){
					printf("\nData is not found\n");
				} else {
					printf("\nPosition is %d\n", ack);
				}
			break;
			
			case 8: /* Delete from last */
			
				if(isEmpty(list)){
					printf("\nList is empty\n");
				} else {
					printf("%d is deleted", list->arr[length]);
					list->length--;	
				}
			break;
			
			case 9: /* Delete from first */
				pos = 0;
				ack = deleteElement(list, pos, &data);
				if(ack == -1){
					printf("\nList is empty\n");
				} else if(ack == -2) {
					printf("\nInvalid position\n");
				} else {
					printf("\n%d is deleted\n", data);
				}
			break;
			
			case 10: /* Delete from position */
				printf("\nEnter the position - ");
				scanf("%d", &pos);
						
				if(pos > list->length){
					printf("\nCan not perform delete operation at that position\n");
				} 	
				ack = deleteElement(list, pos, &data);
				if(ack == -1){
					printf("\nList is empty\n");
				} else if(ack == -2) {
					printf("\nInvalid position\n");
				} else {
					printf("\n%d is deleted\n", data);
				}
			break;
			
			case 11: /* Expend the list */
			
				expandList(list);
			break;
			
			case 12: /* Merge the list */
				
				printf("\nEnter the size of the new list - ");
				scanf("%d", &size);
				
				list2 = init(size);
				
				for(i=0; i<list2->capacity; i++){
					printf("\nEnter the data - ");
					scanf("%d", &data);
					pos = list2->length+1;
					insert(list2, data, pos);
				}
				printf("\nEnter the merging point - ");
				scanf("%d", &pos); 
				mergeAt(list, list2, pos);
				
			break;
			
			case 13: /* Sublist */
				printf("\nEnter the starting index - ");
				scanf("%d", &start);
				printf("\nEnter the ending index - ");
				scanf("%d", &end);
				
				subList(list, start, end);
			break;  						
		}
	}
	return 0;
}
