#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;
	int x;
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	}
	vector<int> temp;
	for(int i = 0; i < n; i++){
		// cout << v[i] << endl;
		if(v[abs(v[i])] < 0){
			temp.push_back(abs(v[i]));
			// cout << "*" << i << endl;
		}
		else{
			v[abs(v[i])] = -v[abs(v[i])];
		}
	}

	for(int j = 0; j < v.size(); j++){
		cout << v[j] << " ";
	}cout << endl;

	for(int j = 0; j < temp.size(); j++){
		cout << temp[j] << " ";
	}
	cout << endl;
	return 0;
}
