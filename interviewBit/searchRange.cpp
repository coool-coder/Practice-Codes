#include <bits/stdc++.h>

using namespace std;

int first(vector<int> &A, int l, int h, int B){
	if(l <= h){
		int mid = l + (h-l)/2;
		if(mid == 0 || B > A[mid-1] && A[mid] == B)
			return mid;
		else if(B > A[mid]){
			return first(A, mid+1, h, B);
		}
		else
			return first(A, l, mid-1, B);
	}
}
int last(vector<int> &A, int l, int h, int B){
	if(l <= h){
		int mid = l + (h-l)/2;
		if(mid == 0 || B < A[mid+1] && A[mid] == B)
			return mid;
		else if(B > A[mid]){
			return last(A, mid+1, h, B);
		}
		else
			return last(A, l, mid-1, B);
	}
}
vector<int> searchRange(vector<int> &A, int B){
	int f = first(A, 0, A.size()-1, B);
	int l = last(A, 0, A.size()-1, B);
	vector<int> temp;
	temp.push_back(f);
	temp.push_back(l);
	return temp;
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n);

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int B;
	cin >> B;
	vector<int> res = searchRange(v, B);
	for(int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}