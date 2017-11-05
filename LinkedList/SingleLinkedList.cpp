//--------------Different operations in singly linked list-----------------//


#include <stdio.h>
#include <iostream>

using namespace std;


struct node{
	int data;
	struct node *right;
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
		void display();
		void insertBegin(int ele);
		linkedList Merge(linkedList l);
		int getSize();
};

node *linkedList::createNewNode(int ele){
	node *temp = new node;
	temp->left = NULL;
	temp->right = NULL;
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
		last->right = temp;
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
		root = root->right;
	}
	return flag;
}

void linkedList::insertAfter(int after, int ele){
	
	if(check(after)){
		node *temp = createNewNode(ele);
		node *tempRoot = first;
		while(tempRoot->data != after)
			tempRoot = tempRoot->right;
		temp->right = tempRoot->right;
		tempRoot->right = temp;
	}
}

void linkedList::insertBegin(int ele){
	node *temp = createNewNode(ele);
	if (first==NULL){
		first = last = temp;
	}
	else{
		temp->right = first;
		first = temp;
	}

}

void linkedList::display(){
	if(first == NULL)
		printf("linkedList is empty\n");
	else{
		node *tempRoot = first;
		while(tempRoot != NULL){
			printf("%d -> ", tempRoot->data);
			tempRoot = tempRoot->right;
		}
		printf("\n");
	}
}

int linkedList::getSize(){
	int len=0;
	node *tempRoot = first;
	while(tempRoot != NULL){
		len++;
		tempRoot = tempRoot->right;
	}
	return len;
}
// --------------Merging two linked list ------------------//
linkedList linkedList::Merge(linkedList l){
	linkedList mergedList;
	int n1 = getSize();
	int n2 = l.getSize();
	node *temp1 = first;
	node *temp2 = l.first;
	node *tempRoot = mergedList.first;
	
	int i=1;
	while(temp1 != NULL && temp2 != NULL){
		if(i%2==0){
			mergedList.insertEnd(temp2->data);
			temp2 = temp2->right;
			i++;

		}else{
			mergedList.insertEnd(temp1->data);
			temp1 = temp1->right;
			i++;
		}
	}
	while(temp1 != NULL){
		mergedList.insertEnd(temp1->data);
		temp1 = temp1->right;
	}
	while(temp2 != NULL){
		mergedList.insertEnd(temp2->data);
		temp2 = temp2->right;
	}	

	return mergedList;
}
//-------------------------------------------------------------------------//

// -------------- Reverse In Groups of k nodes-----------------------------//

void reverseInGroups(linkedList l, int k){
	node *tempRoot = l.first;
	int len = l.getSize();
	int iter = len/k;
	int a[len]={0};
	int i = 0;
	while(tempRoot != NULL){
		a[(i++)] = tempRoot->data;
		tempRoot = tempRoot->right;
	}
	tempRoot = l.first;
	for(i = 0; i < iter*k; i+=k){
		for(int j = k+(i-1); j >= i; j--){
			tempRoot->data = a[j];
			tempRoot = tempRoot->right;
		}
	}
	if(len%k==0)
		l.display();
	else{
		int rem = len-iter*k;
		for(int j = len-1; j >= iter*k; j--){
			tempRoot->data = a[j];
			tempRoot = tempRoot->right;	
		}
		l.display();
	}
}
//-------------------------------------------------------------------------//

//--------------Rotating linkedList counter-clockwise by k nodes-----------//
void rotateLinkedlist(linkedList l, int k){
	node *tempRoot = l.first;
	int len = l.getSize();
	int a[len] = {0};
	int i = 0;
	while(tempRoot != NULL){
		a[i++] = tempRoot->data;
		tempRoot = tempRoot->right;
	}
	tempRoot = l.first;
	int count = 0;
	while(count < len){
		tempRoot->data = a[k%len];
		k++;
		tempRoot = tempRoot->right;
		count++;
	}
	l.display();
}
//-------------------------------------------------------------------------//

int main(){

	int a1[6] = {1,3,5,7,9};
	int a2[10] = {2,4,6,8,10,12,14,16,18,20};

	linkedList L1;
	linkedList L2;

	for(int i = 0; i < 5; i++)
		L1.insertEnd(a1[i]);
	
	for (int i = 0; i < 10; ++i)
		L2.insertEnd(a2[i]);

	
	printf("length:%d\n", L2.getSize());

	printf("linkedList L1: \n");
	L1.display();
	printf("linkedList L2: \n");
	L2.display();
	
	//--------------------Merge two linked lists----------------------//	
	linkedList L3 = L1.Merge(L2);
	printf( "Merged List:\n");
	L3.display();
	//----------------------------------------------------------------//


	//-------------Reversing Linked List in Group of k----------------//
	int k1;
	scanf("%d", &k1);
	reverseInGroups(L2, k1);
	//----------------------------------------------------------------//

	//-------Rotating Linked List counter-clockwise by k-nodes--------//
	int k2;
	cin >> k2;
	rotateLinkedlist(L2, k2);
	//----------------------------------------------------------------//

	return 0;
}