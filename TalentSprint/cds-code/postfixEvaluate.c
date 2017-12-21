#include <stdio.h>
#include <ctype.h>
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

int calculate(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '%': return operand1 % operand2;
    }
}

int evaluatePostfix(char *postfix) {
    stack_t S1 = {500, -1};

    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];
        if (isdigit(token)) {
            push(&S1, token - 48);
        } else {
            int operand2 = onTop(&S1);
            pop(&S1);
            int operand1 = onTop(&S1);
            pop(&S1);
            push(&S1, calculate(token, operand1, operand2));
        }
    }
    return onTop(&S1);
}

int main() {
    printf("%d\n", evaluatePostfix("9732*-+5-"));
    return 0;
}
