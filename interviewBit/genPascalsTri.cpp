//----- generating first n rows of pascal's triangle ------//


#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> generate(int A){
	vector<vector<int> > v;
	
	
	for(int i = 0; i < A+1; i++){
		vector<int> temp;
		for (int j = 0; j <= i; j++)
		{
			if(j==0 || j == i)
				temp.push_back(1);
			else{
				temp.push_back(v[i-1][j-1] + v[i-1][j]); 
			}
		}
		v.push_back(temp);
	}	
	for(int i = 0; i < A; i++){
		for(int j = 0; j <= i; j++){
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
	//return v;
	return v[A];
}


int main(){
	int n;
	cin >> n;
	vector<int> v;
	v = generate(n);
	for(int j = 0; j <= n; j++){
		printf("*%d ", v[j]);
	}
	printf("\n");
	return 0;
}