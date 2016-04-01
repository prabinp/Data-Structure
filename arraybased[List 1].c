/*
 * This program can perform the operations like insert, display and search using the list.h header file.
 */

#include<stdio.h>
#include"List.h"


int main(){
	
	int value, key, ch, get;
	List start;
	
	init(&start);
	
	do {
		
		printf("\n1 - to insert the data");
		printf("\n2 - to display");
		printf("\n3 - to search");
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
			
			case 2:	display(&start);
				break;
			
			case 3: printf("\nEnter the element to search - ");
					scanf("%d",&key);
					
					get = search(&start, key);
					
					if(get == -1){
						printf("\nList is empty\n");
					} else if(get == -2){
						printf("\nData is not found\n");
					} else {
						printf("%d is found at %d position", key, get);
					}
					
				break;
							
			case 0: printf("\nBye....\n");
				break;
			
			default: printf("\nERROR: Wrong input\n");	
				break;	
		} 
		
	} while(ch!=0);
	return 0;	
}

