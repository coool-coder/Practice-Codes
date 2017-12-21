#include <stdio.h>
#include <stdbool.h>

typedef
  struct {
      int size;
      int front;
      int rear;
      int a[1000];
  } cqueue_t;

bool isEmpty(cqueue_t *Q) {
    return Q->front == -1;
}

bool isFull(cqueue_t *Q) {
    return (Q->rear + 1) % Q->size == Q->front;
}

int atFront(cqueue_t *Q) {
    return Q->a[Q->front];
}

void enqueue(cqueue_t *Q, int element) {
    if (isFull(Q)) {
        printf("Queue is full\n");
    } else {
        if (Q->rear == -1) {
            Q->front = Q->rear = 0;
        } else {
            Q->rear = (Q->rear + 1) % Q->size;
        }
        Q->a[Q->rear] = element;
    }
}

void dequeue(cqueue_t *Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty\n");
    } else {
        if (Q->front == Q->rear) {
            Q->front = Q->rear = -1;
        } else {
            Q->front = (Q->front + 1) % Q->size;
        }
    }
}

void dequeue_partEle(cqueue_t *Q){
    if (isEmpty(Q)) {
        printf("Queue is empty\n");
    } else {
        if (Q->front == Q->rear) {
            Q->front = Q->rear = -1;
        } else {
            Q->front = (Q->front + 1) % Q->size;
        }
    }   
}

int main() {
    cqueue_t Q1 = {3, -1, -1};

    for (int i = 10; i <= 40; i += 10) {
        enqueue(&Q1, i);
    }

    dequeue(&Q1);
    dequeue(&Q1);
    if (!isEmpty(&Q1)) {
        printf("At front we have %d\n", atFront(&Q1));
    }
        enqueue(&Q1, 40);

    dequeue(&Q1);

    if (!isEmpty(&Q1)) {
        printf("At front we have %d\n", atFront(&Q1));
    }

    dequeue(&Q1);
    dequeue(&Q1);
    return 0;
}
