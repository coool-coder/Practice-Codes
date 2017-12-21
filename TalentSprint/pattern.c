// printing ABCDEDCBA
//			 ABCDCBA
//			  ABCBA
//			   ABA
//				A
#include <stdio.h>

int main(){
	char Alphabets[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'Z'};
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n ; i++){
		for(int j = 0; j < i; j++){
			printf(" ");
		}
		for(int j = 0; j < n-i-1 ; j++){
			printf("%c", Alphabets[j]);
		}
		for(int j = n-i-1; j >= 0; j--){
			printf("%c", Alphabets[j]);
		}
		printf("\n");
	}
}