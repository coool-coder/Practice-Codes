//aaaabbbbbcccttttt -> a4b5c3t5//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *compress(char *str){
	int len = strlen(str);
	char *compressedStr = (char*)malloc(10000*sizeof(char)); 
	*compressedStr = str[0];
	int i;
	for(i = 0; i < len-1; i++){
		char buffer[50];
		int count = 1;
		while(str[i+1] == str[i]){
			count++;
			i++;
		}
		sprintf(buffer, "%d", count);
		strcat(compressedStr, buffer);
		strcat(compressedStr, str[i]);
	}
	char buffer[50];
	if(str[i] != str[i-1]){
		strcat(compressedStr, str[i]);
		sprintf(buffer, "%d", 1);
		strcat(compressedStr, buffer);
	}
	return compressedStr;
}

int main(){

	char str[1000];
	scanf("%s", str);
	// int len = strlen(str1);


	char *compressedStr = compress(str);
	printf("%s\n", compressedStr);
}
