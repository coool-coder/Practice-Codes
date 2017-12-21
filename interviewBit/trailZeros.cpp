//-------Counting trailing zeros in n!----------// 

#include <iostream>
#include <cmath>
 
using namespace std;

int CountTrailZeros(int n){
	int limit = 5;
	int count = floor(n/limit);
	int sum = 0, i=1;
	while (count >= 1){
		i = i+1;
		sum = sum + count;
		limit = pow(5, i);
		count = floor(n/limit);
	}
	return sum;
}


int main(){
	int n, k;
	cin >> n;
	k = CountTrailZeros(n);
	cout << k << endl;
	return 0;
}
