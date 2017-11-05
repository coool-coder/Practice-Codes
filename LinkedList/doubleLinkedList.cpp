//-----------------Different Operations in Doubly Linked List--------------------//

#include <stdio.h>
#include <iostream>

using namespace std;

struct node{
	int data;
	struct node *prev;
	struct node *next;
};


class linkedList{
	public:
		node *first;
		node *last;	
		linkedList(){
			first = NULL;
			last = NULL;
		}
		node *createNewNode(int ele);
		void insertEnd(int ele);
		void insertAfter(int after, int ele);
		int check(int ele);
		void displayFront();
		void displayReverse();
		void insertBegin(int ele);
		// linkedList Merge(linkedList l);
		int getSize();
};

node *linkedList::createNewNode(int ele){
	node *temp = new node;
	temp->prev = NULL;
	temp->next = NULL;
	temp->data = ele;
	return temp; 
}

void linkedList::insertEnd(int ele){
	node *temp = createNewNode(ele);
	if (first == NULL){
		first = temp;
		last = temp; 
	}
	else{
		temp->prev = last;
		last->next = temp;
		last = temp;
	}
}

int linkedList::check(int ele){
	int flag=0;
	node *root = first;
	while(root!=NULL){
		if(root->data == ele){
			flag = 1;
			break;
		}
		root = root->next;
	}
	return flag;
}

void linkedList::insertAfter(int after, int ele){
	
	if(check(after)){
		node *temp = createNewNode(ele);
		node *tempRoot = first;
		while(tempRoot->data != after)
			tempRoot = tempRoot->next;
		tempRoot->next->prev = temp;
		temp->next = tempRoot->next;
		tempRoot->next = temp;
		temp->prev = tempRoot;
	}else{
		printf("Given element is not present in linked list\n");
	}
}

void linkedList::insertBegin(int ele){
	node *temp = createNewNode(ele);
	if (first==NULL){
		first = last = temp;
	}
	else{
		first->prev = temp;
		temp->next = first;
		first = temp;
	}
}

void linkedList::displayFront(){
	if(first == NULL)
		printf("linkedList is empty\n");
	else{
		node *tempRoot = first;
		while(tempRoot != NULL){
			printf("%d <--> ", tempRoot->data);
			tempRoot = tempRoot->next;
		}
		printf("\n");
	}
}

void linkedList::displayReverse(){
	if(first == NULL)
		printf("linkedList is empty\n");
	else{
		node *tempRoot = last;
		while(tempRoot != NULL){
			printf("%d <--> ", tempRoot->data);
			tempRoot = tempRoot->prev;
		}
		printf("\n");
	}
}

int linkedList::getSize(){
	int len=0;
	node *tempRoot = first;
	while(tempRoot != NULL){
		len++;
		tempRoot = tempRoot->next;
	}
	return len;
}

int main(){

	linkedList L1;
	int a[10] = {1,4,2,6,3,7,9,5,10,11};

	for(int i = 0; i < 10; i++){
		L1.insertEnd(a[i]);
	}
	printf("printing linkedList in succesive order\n");
	L1.displayFront();
	printf("printing linkedList in reverse order\n");
	L1.displayReverse();

	printf("Adding 13 after 7\n");
	L1.insertAfter(7, 13);
	printf("printing linkedList in succesive order\n");
	L1.displayFront();
	printf("printing linkedList in reverse order\n");
	L1.displayReverse();



	return 0;
}	