#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int mystrcmp(char s1[], char s2[]){
	for(int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++){
		if (s1[i] != s2[i])
		return s1[i] - s2[i];
	}
	return 0;
}

int countWords(char s[]){
	int count = 0;
	for(int i = 0; s[i] != '\0'; i++){
		if (isspace(s[i])){
			if(i!=0){
				count++;
			}
			while(s[i]>33){
				i++;
			}
		}
	}
	return count + 1;
}

int fact(int n){
	int f=1;
	for(int i=1; i<=n; i++){
		f*=i;
	}
	return f;
}

