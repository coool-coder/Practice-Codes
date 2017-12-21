#include <stdio.h>
#include <stdbool.h>

typedef
  struct {
      int size;
      int front;
      int rear;
      int a[1000];
  } queue_t;

bool isEmpty(queue_t *Q) {
    return Q->front == -1;
}

bool isFull(queue_t *Q) {
    return Q->rear == Q->size - 1;
}

int atFront(queue_t *Q) {
    return Q->a[Q->front];
}

void enqueue(queue_t *Q, int element) {
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

int main() {
    queue_t Q1 = {5, -1, -1};

    for (int i = 10; i <= 60; i += 10) {
        enqueue(&Q1, i);
    }

    if (!isEmpty(&Q1)) {
        printf("At front we have %d\n", atFront(&Q1));
    }

    dequeue(&Q1);
    dequeue(&Q1);
    dequeue(&Q1);

    if (!isEmpty(&Q1)) {
        printf("At front we have %d\n", atFront(&Q1));
    }

    dequeue(&Q1);
    dequeue(&Q1);
    dequeue(&Q1);

    return 0;
}
