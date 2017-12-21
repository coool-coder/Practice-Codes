#include<stdio.h>
#include<stdbool.h>
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

typedef
  struct {
      int size;
      int front;
      int rear;
      node* a[1000];
  } queue_t;

bool isEmpty(queue_t *Q) {
    return Q->front == -1;
}

bool isFull(queue_t *Q) {
    return Q->rear == Q->size - 1;
}

node* atFront(queue_t *Q) {
    return Q->a[Q->front];
}

void enqueue(queue_t *Q, node* element) {
    if (isFull(Q)) {
        printf("Queue is full\n");
    } else {
        if (Q->rear == -1) {
            Q->front = Q->rear = 0;
        } else {
            Q->rear++;
        }
        Q->a[Q->rear] = element;
    }
}

void dequeue(queue_t *Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty\n");
    } else {
        if (Q->front == Q->rear) {
            Q->front = Q->rear = -1;
        } else {
            Q->front++;
        }
    }
}

void levelByLevel(node *r) {
    node *temp;
    queue_t Q = {1000, -1, -1};

    enqueue(&Q, r);
    while (!isEmpty(&Q)) {
        temp = atFront(&Q);
        dequeue(&Q);
        printf("%d ", temp->data);
        if (temp->lchild) {
            enqueue(&Q, temp->lchild);
        }
        if (temp->rchild) {
            enqueue(&Q, temp->rchild);
        }
    }
}

int main() {
int a[]={40, 20, 70, 10, 30, 60, 50, 90, 80};
node *root = NULL;

    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
                add(&root, a[i]);

    levelByLevel(root);
    printf("\n");
return 0;
}
