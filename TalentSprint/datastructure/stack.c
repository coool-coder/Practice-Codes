// implementing stack using linked list //

#include <stdio.h>
#include <stdlib.h>

typedef
struct Single{
	int data;
	struct Single *next;
}node;


typedef
struct{
	node *first;
	node *last; 
}List;

node *newNode(int element){
	node *temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	temp->data = element;
	return temp;
}

int isEmpty(List *L){
	if (L->first == NULL)
		return 1;
	else
		return 0;
}
void push(List *L, int element){
	node *temp = newNode(element);
	if(L->last == NULL){
		L->first = L->last = temp;
	}
	else{
		L->last->next = temp;
		L->last = temp;	
	}
}

node *findNode(List *L, int element){

	for(node* f = L->first; f != NULL; f = f->next){
		if(f->data == element){
			return f;
		}
	}
	return NULL;
}

int getElement(List *L){
	if(L->first==NULL)
		return NULL;
	else{
		return L->last->data;
	}
}
int getSize(node *n){
	if(n == NULL)
		return 0;
	else{
		int count = 0;
		// node *temp = n;
		while(n != NULL){
			n = n->next;
			count++;
		}
		return count;
	}
}

void pop(List *L){
	if(!isEmpty(&L)){
		if(getSize(L->first) > 1){
			node *temp = L->first;
			while(temp->next != L->last)
				temp = temp->next;
			
			temp->next = NULL;
			L->last	= temp;
		}
		else{
			L->first = NULL;
			L->last  = NULL;
		}
	}
}

void display(List *L){
	if(L->first == NULL)
		printf("Linked List is empty\n");
	else{
		node *f;
		for(f = L->first; f != NULL; f = f->next){
			printf("%d -> ", f->data);
		}
		printf("\n");
	}
}

int main(){
	List L = {NULL, NULL};
	push(&L, 19);
	for(int i = 0; i < 10; i++)
		push(&L, i);
	
	display(&L);
	pop(&L);
	display(&L);
	while(!isEmpty(&L)){
		printf("%d <- ", getElement(&L));
		pop(&L);
	}
	printf("\n");
	printf("%d\n", isEmpty(&L));
	pop(&L);
	display(&L);
	
	return 0;
}