// Implementing traversing technique: Postorder, Preorder, and Inorder //

#include <stdio.h>
#include <stdlib.h>

typedef
struct bst_t{
	struct bst_t *left;
	int data;
	struct bst_t *right;
}node;

node *newNode(int element){
	node *temp = (node*)malloc(sizeof(node));
	temp->left = NULL;
	temp->data = element;
	temp->right = NULL;

	return temp;
}

void bst(node **root, int element){
	node *curr = newNode(element);
	node *parent;
	if(*root == NULL)
		*root = curr;
	else{
		node *tr = *root;
		while(tr != NULL){
			parent = tr;
			if(curr->data < tr->data)
				tr = tr->left;
			else
				tr = tr->right;
		}
		
		if (element < parent->data) {
            parent->left = curr;
        } 
        else {
            parent->right = curr;
        }
	}
}

void preorder(node *root){
	if(root != NULL){
		printf("%d ", root->data);
		if(root->left != NULL)
			preorder(root->left);
		if(root->right != NULL)
			preorder(root->right);
	}
}

void postorder(node *root){
	if(root != NULL){
		if(root->left != NULL)
			postorder(root->left);
		if(root->right != NULL)
			postorder(root->right);
		printf("%d ", root->data);

	}
}

void inorder(node *root){
	if(root != NULL){
		if(root->left != NULL)
			inorder(root->left);
		printf("%d ", root->data);
		if(root->right != NULL)
			inorder(root->right);
	}
}

int main(){
	node *root = NULL;
	int datas[] = {50, 25, 10, 30, 40, 60, 70, 20, 90};
	for(int i = 0; i < 9; i++){
		bst(&root, datas[i]);
	}
	printf("PostOrder: ");
	postorder(root);
	printf("\n");

	printf("InOrder: ");
	inorder(root);
	printf("\n");

	printf("PreOrder: ");
	preorder(root);
	printf("\n");

	return 0;

}