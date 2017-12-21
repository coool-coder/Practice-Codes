#include <stdio.h>
#include <stdlib.h>	

typedef
struct{
	int top;
	int size;
	int a[1000];
}stack_t;

int isFull(stack_t *s){
	if(s->size == s->top)
		return 1;
	else
		return 0;
}

int isEmpty(stack_t *s){
	if(s->top == 0)
		return 1;
	else
		return 0;
}

void push(stack_t *s, int ele){

	if(isFull(s)){
		printf("stack is full\n");
	}else{
		s->a[s->top++] = ele;
	}
}

void pop(stack_t *s){
	if(isEmpty(s))
		printf("Nothing to pop\n");
	else{
		printf("Element popped from stack: %d\n", s->a[s->top-1]);
		s->a[s->top--] == -1;
	}
}

void display(stack_t *s){
	if(isEmpty(s))
		printf("Stack is Empty\n");
	else{
		for(int i = 0; i < s->top; i++)
			printf("%d ", s->a[i]);
		printf("\n");
	}
}

int main(){
	stack_t s = {0, 10, -1};
	for(int i = 0; i < 10; i++){
		push(&s, i);
	}
	display(&s);
	printf("length of stack: %d\n", s.top);
	pop(&s);
	display(&s);

	return 0;
}