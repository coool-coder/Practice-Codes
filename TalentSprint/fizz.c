#include<stdio.h>
int checkMultiple(int n) {
	if(n % 5 == 0 && n % 3 == 0) {
		return 1;
	}
	else if(n % 5 == 0) {
		return 5;
	}
	else if(n % 3 == 0){
		return 3;
	}
	else{
		return 0;
	}
}
int main() {
	int num;
	scanf("%d", &num);
	if(checkMultiple(num) == 1){
		printf("FIZZBIZZ\n");
	}
	if(checkMultiple(num) == 5){
		printf("FIZZ\n");
	}
	if(checkMultiple(num) == 3){
		printf("BIZZ\n");
	}
	if(checkMultiple(num) == 0){
		printf("%d\n", num);
	}
}

