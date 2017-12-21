#include<stdio.h>
#include<stdlib.h>

typedef
    struct bst {
    struct bst *lchild;
    int data;
    struct bst *rchild;
} node;

node *newNode(int element) {
    node *temp = (node *) malloc(sizeof(node));
    temp->data = element;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

void add(node **root, int element) {
    node *temp;
    node *tr;
    node *parent;
    temp = newNode(element);
    if (*root == NULL) {
        *root = temp;
    } else {
        tr = *root;
        while (tr != NULL) {
            parent = tr;
            if (element < tr->data) {
                tr = tr->lchild;
            } else {
                tr = tr->rchild;
            }
        }

        if (element < parent->data) {
            parent->lchild = temp;
        } else {
            parent->rchild = temp;
        }
    }
}

void inorder(node *r) {
    if (r) {
        if (r->lchild) {
            inorder(r->lchild);
        }
        printf("%4d", r->data);
        if (r->rchild) {
            inorder(r->rchild);
        }
    }
}

void postorder(node *r) {
    if (r) {
        if (r->lchild) {
            postorder(r->lchild);
        }
        if (r->rchild) {
            postorder(r->rchild);
        }
        printf("%4d", r->data);
    }
}

void preorder(node *r) {
    if (r) {
        printf("%4d", r->data);
        if (r->lchild) {
            preorder(r->lchild);
        }
        if (r->rchild) {
            preorder(r->rchild);
        }
    }
}

int main() {
int a[]={40, 20, 70, 10, 30, 60, 50, 90, 80};
node *root = NULL;

    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
                add(&root, a[i]);

    printf("Postorder\n");
    postorder(root);
    printf("\n");

    printf("Inorder\n");
    inorder(root);
    printf("\n");

    printf("Preorder\n");
    preorder(root);
    printf("\n");
return 0;
}
