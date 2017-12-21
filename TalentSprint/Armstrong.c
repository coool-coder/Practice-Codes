#include <stdio.h>
#include <math.h>

int main(){
	int n;
	scanf("%d", &n);
	int temp = n;

	int len_digits = floor(log10(abs(n))) + 1;

	int sum = 0;
	int rem;
	for(int i = 1; i <= len_digits; i++){
		rem = n%10;
		sum = sum + pow(rem, len_digits);
		n = n/10;
	}

	if(sum == temp)
		printf("Given no. is a Armstrong no.\n");

	else
		printf("Given no. is not a Armstrong no.\n");
}