#include <stdio.h>

int countDigits(int n){
	char s[20];
	return sprintf(s, "%d", n);
}

int summOfDigits(int n){
	int sum = 0;
	while(n){
		sum = sum + n%10;
		n /= 10;
	}
	if (countDigits(sum)==1)
		return sum;
	else
		summOfDigits(sum);
}

int main(){
	int n;
	scanf("%d", &n);
	int Lucky_no = summOfDigits(n);
	printf("lucky number:- %d\n", Lucky_no);
	return 0;
}