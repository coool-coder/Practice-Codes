#include <stdio.h>
#include <stdbool.h>

typedef 
 struct {
    int size;
    int top;
    int a[1000];
 } stack_t;

bool isEmpty(stack_t *S) {
        return S->top == -1;
}

bool isFull(stack_t *S) {
    return S->top == S->size - 1;
}

int onTop(stack_t *S) {
    return S->a[S->top];
}

void push(stack_t *S, int element) {
    if (isFull(S)) {
        printf("Stack full.\n");
    } else {
        S->top++;
        S->a[S->top] = element;
    }
}

void pop(stack_t *S) {
    if (isEmpty(S)) {
        printf("Stack empty.\n");
    } else {
        S->top--;
    }
}

int main() {
    stack_t S1 = {5, -1};

    for (int i = 10; i <= 60; i += 10) {
            push(&S1, i);
        }

    if (!isEmpty(&S1)) {
        printf("On top we have %d\n", onTop(&S1));
    }

    pop(&S1);
    pop(&S1);
    pop(&S1);

    if (!isEmpty(&S1)) {
        printf("On top we have %d\n", onTop(&S1));
    }

    while (!isEmpty(&S1)) {
        pop(&S1);
    }
    
        pop(&S1);
    return 0;
}
