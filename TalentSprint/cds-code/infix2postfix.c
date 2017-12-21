#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

typedef 
 struct {
    int size;
    int top;
    char a[1000];
 } stack_t;

bool isEmpty(stack_t *S) {
        return S->top == -1;
}

bool isFull(stack_t *S) {
    return S->top == S->size - 1;
}

char onTop(stack_t *S) {
    return S->a[S->top];
}

void push(stack_t *S, char element) {
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

int infix_priority(char operator) {
    switch (operator) {
        case '(': return 4;
        case '*':
        case '/':
        case '%': return 3;
        case '+':
        case '-': return 2;
    }
}

int stack_priority(char operator) {
    switch (operator) {
        case '(': return 1;
        case '*':
        case '/':
        case '%': return 3;
        case '+':
        case '-': return 2;
    }
}

void infix2postfix(char *infix, char *postfix) {
    char token;
    int j = 0;
    stack_t S1 = {500, -1};

    for (int i = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        if (isdigit(token)) {
            postfix[j++] = token;
        } else {
            if (isEmpty(&S1)) {
                push(&S1, token);
            } else if (token == ')') {
                while (onTop(&S1) != '(') {
                    postfix[j++] = onTop(&S1);
                    pop(&S1);
                }
                pop(&S1);
            } else if (infix_priority(token) > stack_priority(onTop(&S1))) {
                push(&S1, token);
            } else {
                postfix[j++] = onTop(&S1);
                pop(&S1);
                push(&S1, token);
            }
        }
    }

        while (!isEmpty(&S1)) {
            postfix[j++] = onTop(&S1);
            pop(&S1);
        }
        postfix[j++] = '\0';
}

int main() {
    char postfix[200];
    char infix[] = "9+(7-3*2)-5";

    infix2postfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}
