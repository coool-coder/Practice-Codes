// Rotating a string by n rotations and printing the result//
//eeeaaabbb -> 5 rotations


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(){

	char s[1000];

	int n;
	printf("input string and then hit enter\n");
	scanf("%[^\n]s", s);
	printf("Provide no. of rotations:\n");
	scanf("%d", &n);

	int len = strlen(s);
	char *copy = (char*)malloc(len*sizeof(char));

	int st = n%len;
	int count = 0; 
	while(count < len){
		copy[st%len] = s[count];
		count++;
		st++;
	}

	printf("string after %d rotations: %s\n", n, copy);

	return 0;
}