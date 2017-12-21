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

void insertEnd(List *L, int element){
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
 
void insertBegin(List *L, int element){
	node *temp = newNode(element);
	if(L->last == NULL){
		L->first = L->last = temp;
	}
	else{
		temp->next = L->first;
		L->first = temp;
	}
}

void insertAfter(List *L, int ele1, int ele2){
	node *f = findNode(L, ele1);
	if (f != NULL){
		node *temp = newNode(ele2);
		temp->next = f->next;
		f->next = temp;
	}
}

void deleteNode(List *L, int ele){
	node *f = findNode(L, ele);
	if(f!=NULL){
		node *current;
		for(current = L->first; current->next != f; current = current->next);
		current->next = f->next;
	}
}

void deleteEnd(List *L){
	node *temp = L->first;
	while(temp->next != L->last)
		temp = temp->next;
	
	temp->next = NULL;
	L->last	= temp;
}

void display(List *L){
	if(L == NULL)
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
	insertEnd(&L, 10);
	insertEnd(&L, 20);
	insertBegin(&L, 17);
	insertAfter(&L, 17, 19);
	insertAfter(&L, 10, 25);
	display(&L);
	deleteNode(&L, 10);
	display(&L);
	deleteEnd(&L);
	display(&L);
	return 0;
}
