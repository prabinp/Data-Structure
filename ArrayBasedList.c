/* This is a array list program implemented in c
 * Operation - Basic operations
 */
 
#include<stdio.h>
#include"List.h"

int main(){
	
	int value, key, ch, get, space, pos;
	List start;
	
	init(&start);
	
	do {
		
		printf("\n1 - to insert the data");
		printf("\n2 - to insert at beginning");
		printf("\n3 - to insert at position");
		printf("\n4 - to display");
		printf("\n5 - to search");
		printf("\n6 - to remove from beginning");
		printf("\n7 - to remove from end");
		printf("\n8 - to remove at position");
		printf("\n9 - to sort the list");
		printf("\n0 - to exit");
		
		printf("\nEnter your option - ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1: while(start.length != start.size) {
							
							printf("\nEnter the data [ Enter 0 to terminate the insertion ] - ");
		
							scanf("%d",&value);
		
							if(value == 0){
								break;
							} else {
								insert(&start, value);
							}
						}
					if(start.length == start.size){
						printf("\nList is full\n");
					}
					
					printf("\nList length - %d\n",start.length);
				
				break;
			
			case 2: if(isFull(&start)){
						printf("\nList is full");
					} else {
	 
						printf("\nEnter the data - ");
						scanf("%d", &key);
						get = insertAtBeg(&start, key);
								
						if(get==1){
							printf("\nSuccessfull operation\n");
						}
					}
				break;
			
			case 3: if(isFull(&start)){
						printf("\nERROR: Data can not be insert. List is full\n");
					} else if(isEmpty(&start)){
						printf("\nERROR: List is empty\n");
					}
					else {
						printf("\nEnter the position - ");
						scanf("%d", &pos);
					
						printf("\nEnter the data - ");
						scanf("%d",&value);
							
						get = insertAtPos(&start, value, pos-1);
						
						if(get==1){
							printf("\nData is inserted\n");
						} else {
							printf("\nUnsuccessfull operation\n");
						}
				}
				break;
				
			case 4:	display(&start);
				break;
			
			case 5: printf("\nEnter the element to search - ");
					scanf("%d",&key);
					
					get = search(&start, key);
					
					if(get == -1){
						printf("\nList is empty\n");
					} else if(get == -2){
						printf("\nData is not found\n");
					} else {
						printf("%d is found at %d position", key+1, get);
					}
				break;
			
			case 6: if(isEmpty(&start)){
						printf("\nERROR: List is empty\n");
					} else {
						get = removeAtBeg(&start);
						
						if(get==1){
							printf("\nData is removed\n");
						} else {
							printf("\nUnsuccessfull operation\n");
						}
					}
				break;
				
			case 7: if(isEmpty(&start)){
						printf("\nERROR: List is empty\n");
					} else {
						get = removeFromEnd(&start);
						if(get==1){
							printf("\nData is removed\n");
						} else {
							printf("\nUnsuccessfull operation\n");
						}
					}
				break;			
		
			case 8: if(isEmpty(&start)){
						printf("\nERROR: List is empty\n");
					} else {				 
						printf("\nEnter the position - ");
						scanf("%d", &key);
								
						get = removeAtPos(&start, key);
						if(get==1){
							printf("\nData is removed\n");
						} else {
							printf("\nUnsuccessfull operation\n");
						}
					}	
				break;
				
			case 9: sortList(&start);
				break;						
			
			case 0: printf("\nBye...\n");
				break;
			
			default: printf("\nERROR: Wrong input\n");	
				break;	
		} 
		
	} while(ch!=0);
	return 0;	
}
