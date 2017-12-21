#include<stdio.h>
//#include "fact.h"
#include "stdlib.h"

int fact(int);
int mystrcmp(char*, char*);
int countWords(char*);

int main(){
	printf("%d\n",fact(6));
	printf("%d\n", mystrcmp("chandu", "chandrakant"));
	printf("%d\n", countWords("listning songs is one of my hobbies"));
	return 0;
}
