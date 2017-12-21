// Printing palindromic nos. in a given range of numbers //

#include <stdio.h>

int is_palindrome(int num){
	int sum = 0;
	int temp = num;
	int rem;
	while(num > 0){
		rem = num%10;
		sum = 10*sum + rem;
		num = num/10;	
	}
	if(sum == temp)
		return 1;
	else
		return 0;
}

int main(){
	int n, m;
	int flag = 0;
	scanf("%d %d", &m, &n);

	int count = 0;

	for(int i=m; i <= n; i++){
		if (is_palindrome(i)){
			printf("%d ", i);
			flag = 1;
			count+=1; 
		}
	}
	
	if(flag == 0)
		printf("There are no palindrome nos. in between the given ranges\n");

	else
		if(count > 1)
			printf("are palindrome nos.\n");
		else
			printf("is a palindrome number\n");

	return 0;
}