#include <bits/stdc++.h>

using namespace std;

int findDuplicates(vector <int>&A){
	int j = 0;
    int n = A.size();
    
    if(n == 0 || n == 1)
        return n;
    int temp = INT_MIN;
    for(int i = 0; i < A.size() - 1; i++){
        if(A[i] != A[i + 1]){
            A[j++] = A[i];
            if(temp != INT_MIN){
            	A[j++] = A[i];
            	temp = INT_MIN;
            }
        }
        else if(temp == INT_MIN){
        	temp = A[i];
        }
    }
    
    A[j++] = A[n-1];
    if(temp != INT_MIN){
        A[j++] = A[n-1];
    }
    return j;
}

int main(){

	int n;
	cin >> n;
	int x;
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	}
	int ind = findDuplicates(v);
	for(int i = 0; i < ind; i++){
		cout << v[i] << " ";
	}cout << endl;
	return 0;
}
