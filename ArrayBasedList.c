/* This is a array list program implemented in c
 */
 
#include<stdio.h>

typedef struct ArrayBasedList {
	int size;
	int array[10];
	int length;
} List;


List init(List start,int length, int size);
List insert(List start, int value);
void display(List start);

int main(){
	
	int value;
	List start;
	
	start = init(start, 0, 10);
	
	printf("\nEnter the data [ Enter 0 to terminate the insertion ]\n");
	
	while(start.length != start.size) {
		
		scanf("%d",&value);
		
		if(value == 0){
			break;
		} 
		
		else if(start.length == start.size){
			printf("\nList is full\n");
		}
		
		else {
				start = insert(start, value);
		}
	}
	
	printf("\nList length - %d\n",start.length);
	
	display(start);

	return 0;	
}


List init(List start, int length, int size){
	
	start.length = length;
	start.size = size;
	
	printf("\nInitialization done...\nSize of the list - %d\n\n",start.size);
	
	return (start);
}


List insert(List start, int value) {
	
	start.array[start.length] = value;
	start.length++;
	
	return (start);
}

void display(List start){
	int i=0;
	while(i != start.length){
		printf("\n%d",start.array[i]);
		i++;
	}
}
