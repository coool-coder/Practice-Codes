#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


vector<int> getRow(int n){
	int sum = 1;
	vector<int> v;
	for(int i = 0; i <= n; i++){
		if(i!=n)
			v.push_back(sum);
		else if(i==n)
			v.push_back(1);
		sum = sum + v[i];
	}

	for(int i = 0; i <= n; i++){
		vector<int> temp;
		for(int j = 0; j <= n; j++){
			if(j==0 || j==n)
				temp.push_back(1);
		}
	}

	for(int i = 0; i <= n; i++)
		printf("%d\n", v[i]);
	return v;
}

int main(){

	int n;
	cin>>n;
	vector<int> k = getRow(n);
	// cout << k << endl;

	return 0;
}