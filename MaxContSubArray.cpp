//-------------Finding maximum contiguous sum of subarray-----------// 

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int MaxContiguous(vector<int> v){
	int n = v.size();
	int MaxSum = 0, Cont_Sum = 0;
	for(int i=0; i<n; i++){
		Cont_Sum = Cont_Sum + v[i];
		if(MaxSum < Cont_Sum)
			MaxSum = Cont_Sum;

		if (Cont_Sum < 0)
			Cont_Sum = 0;
	}
	return MaxSum;
}

int main(){
	int n;
	cin>>n;
	int x;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin>>x;
		v.push_back(x);
	}
	int MaxSum = MaxContiguous(v);
	printf("%d\n", MaxSum);
	printf("string");
	return 0;
}
