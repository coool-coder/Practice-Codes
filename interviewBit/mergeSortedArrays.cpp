#include <bits/stdc++.h>

using namespace std;

int main(){
	int m, x;
	cin >> m;
	vector<int> A;
	for(int i = 0; i < m; i++){
		cin >> x;	
		A.push_back(x);
	}
	
	int n;
	cin >> n;
	vector<int> B;
	for(int i = 0; i < n; i++){
		cin >> x;	
		B.push_back(x);
	}
    
    vector <int> temp;
    int i = 0, j = 0;
    while(i < A.size() && j < B.size()){
        if(A[i] < B[j]){
            temp.push_back(A[i++]);
        }else{
            temp.push_back(B[j++]);
        }
    }
    while(i < A.size()){
        temp.push_back(A[i++]);
    }
    while(j < B.size()){
        temp.push_back(B[j++]);
    }
    i = 0;
    while(i < temp.size())
    	cout << temp[i++] << " ";
    cout << endl;
    i = 0;
    while(i < A.size()){
        A[i] = temp[i];
        i++;
    }
   
    while(i < temp.size()){
        A.push_back(temp[i++]);
    }
    i = 0;
    while(i < temp.size())
    	cout << A[i++] << " ";
    cout << endl;

	return 0;

}