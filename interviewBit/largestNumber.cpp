// Given a list of non negative integers, arrange them such that they form the largest number.
//For example:
//Given [3, 30, 34, 5, 9], the largest formed number is 9534330

#include <bits/stdc++.h>

using namespace std;

string intToStr(int n){
	char buffer[1000000];
	sprintf(buffer, "%d", n);
	return buffer;
}

int myCompare(string X, string Y){
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1: 0;
}

void largestNum(vector<int> A){
	int len = A.size();
    int flag = 0;

    vector<string> temp1;
	
	for(int i = 0; i < len; i++){
		if(A[i] > 0){
			flag = 1;
			break;
		}
	}

	for(int i = 0; i < len; i++){
		temp1.push_back(intToStr(A[i]));
	}

	sort(temp1.begin(), temp1.end(), myCompare);
	char str[1000000];
	
	// for(int i = 0; i < temp1.size(); i++){
	//     cout << temp1[i] << " ";
	// }
	string st;
	st = accumulate(temp1.begin(), temp1.end(), st);	
	
	if(flag == 1)
		cout << st << endl;

	else
		cout << "0" << endl;
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
	largestNum(v);
	// string str = largestNum(v);

	return 0;
}