#include <bits/stdc++.h>

using namespace std;

int main(){
	string A;
	cin >> A;
	long long i = 0;
	long long sign = 0;
	if(A[0] == '-'){
		sign = -1;
		i++;
	}
	else if(A[0] == '+'){
		sign = 1;
		i++;
	}
	int n = A.length();
	long long integer = 0;
	while(1){
		if(int(A[i])-'0' < 0 || int(A[i])-'0' > 9 || i > n){
			break;
		}
		else{
			integer = integer*10 + (int(A[i])-'0'); 
		}
		i++;
	}
	
	if(sign < 0 && integer > 0) integer = -integer;
	
	if(integer < INT_MIN)
	    cout << INT_MIN << endl;
	else if(integer >= INT_MAX )
	    cout << INT_MAX << endl;
	else
	    cout << integer << endl;
}