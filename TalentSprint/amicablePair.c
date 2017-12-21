//---Two numbers are called Amicable if each equals to the sum of the all the factors of the other----//

#include <stdio.h>
#include <math.h>

unsigned long long factorsSum(unsigned long long n){
	unsigned long long sum=1;
	int i = 2;
	while(i < sqrt(n)){
		if (n%i == 0){
			sum += i + n/i;
		}		
		i++;
	}
	if(i*i == n){
		sum+=i;
	}
	return sum;
}

void ap(unsigned long long m){
	unsigned long long n = factorsSum(m);
	if(m < n && m == factorsSum(n))
		printf("%llu %llu\n", m, n);
}

int main(){
	for(unsigned long long i = 220; i <= 10000000; i++)
		ap(i);
	return 0;
}