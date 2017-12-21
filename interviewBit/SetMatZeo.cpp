//Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.
#include <bits/stdc++.h>
using namespace std;

	
int check(vector<int> v, int k){
	for(int i = 0; i < v.size(); i++){
		if(v[i] == k)
			return 1;	
	}
	return 0;
}

void setMatZeros(vector<vector<int> > &A){
	int r = A.size();
	int c = A[0].size();
	vector<int> rows;
	vector<int> cols;

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(A[i][j] == 0){
				// cout<< i <<" "<< j <<endl;
				if(!check(rows, i))  
					rows.push_back(i);
				if(!check(cols, j))
					cols.push_back(j);
			}
		}
	}
	for(int i = 0; i < rows.size(); i++){
		for(int j = 0; j < c; j++){
			A[rows[i]][j] = 0;
		}
	}
	for(int i = 0; i < cols.size(); i++){
		for(int j = 0; j < r; j++){
			A[j][cols[i]] = 0;
		}
	}
}

int main(){

	int m, n;
	cin >> m;
	cin >> n; 
	vector<vector<int> >v(m, vector<int>(n,0));
	
	int x;
	for (int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; j++){
			cin >> x;
			v[i][j] = x;
		}
	}
	// cout << "\nrow:" << v.size() << " col:"<< v[0].size() << endl;
	
	setMatZeros(v);
	for (int i = 0; i < m; ++i){
		for(int j = 0; j < n; j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	// string str = largestNum(v);

	return 0;
}