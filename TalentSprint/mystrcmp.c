#include <stdio.h>
#include <string.h>

// int countWords(){

// }



// int mystrcmp(char s1[], char s2[]){
// 	int flag = 0;
// 	for(int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++){
// 		if (s1[i] != s2[i])
// 			return s1[i] - s2[i];
// 	}
// 	return 0;
// 	// printf("%d\n", flag);

// }
int main(){
	// char s1[] = "what";
	// char s2[] = "when";
	// int flag = mystrcmp(s1, s2);
	// printf("%d\n", flag);
	char s[100000] ;
	s = gets();
	// scanf("%[^\n]s", s);
	printf("%s\n", s);
	return 0;
}