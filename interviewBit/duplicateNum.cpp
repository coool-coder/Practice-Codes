//Given a read only array of n + 1 integers between 1 and n, 
//find one number that repeats in linear time using less than O(n) space 
//and traversing the stream sequentially O(1) times. //
//input: [3 4 1 4 1]
//output: 1

#include <bits/stdc++.h>

using namespace std;

int duplicateNum(vector<int> A){
	int len = A.size();
	int ind[100000] = {0};
	for(int i = 0; i < len; i++){
		ind[A[i]] += 1;
	}
	int i = 1;
	int num = 0;
	while(i < len){
		if(ind[i] > 1){
			num = i;
			break;
		}
		i++;
	}
	try{
		if (num != 0)
			return num;
		else
			return -1;
	}
	catch (runtime_error e){
		throw runtime_error(e);
	}	

}

int main(){

	int n;
	cin >> n;
	vector<int> v;
	int x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}
	int k = duplicateNum(v);
	// string str = largestNum(v);
	cout << k << endl;
	return 0;
}
