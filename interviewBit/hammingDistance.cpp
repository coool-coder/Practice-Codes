#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

string binTodec(int num){
	int rem;
	// string s;
	stringstream ss;
	rem = (num%2);
	ss << rem;
	// ss << endl;
	string s = ss.str();
	num = num/2;
	while(num != 0){
		stringstream ss;
		rem = num%2;
		ss << rem;
		s = ss.str() + s; 
		num = num/2;

	}
	return s;

}

int HammingDistance(int a, int b){
	string s1;
	string s2;
	int count=0;
	s1 = binTodec(a);
	s2 = binTodec(b);

	int n1 = s1.size();
	int n2 = s2.size();

	if (n1 < n2){
		for(int i=0; i<(n2-n1); i++){
			s1 = '0' + s1;
		}
	}
	else if (n2 <= n1){
		for(int i=0; i<(n1-n2); i++){
			s2 = '0' + s2;
		}
	}
	for(int i=0; i<s2.size(); i++){
		if(s1[i]!=s2[i])
			count+=1;
	}
	return count;
}

int main(){
	vector<int> A;
	int n;
	cin >> n;
	int x;
	// cout << n;
	for(int i=0; i<n; i++){
		cin>>x;
		A.push_back(x);
	}

	int sum=0;
	int dist;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if (j!=i){
				dist = HammingDistance(A[i], A[j]);
				cout << "hamming distance of "<<A[i]<<" and "<<A[j]<< " is "<<dist<<endl;
				sum += 2*dist;
			}
		}
	}
	cout << sum << endl;
}