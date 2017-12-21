#include <iostream>
#include <cstdio>

using namespace std;

void unique(int A, int B){
	int a[A][B] = {0};
	int count = 0;
	for(int i = 0; i < A; i++){
		a[i][0] = 1;
	}
	for(int i = 0; i < B; i++){
		a[0][i] = 1;
	}

	for(int i = 1; i < A; i++){
		for(int j = 1; j < B; j++){
			a[i][j]+=a[i-1][j] + a[i][j-1];
		}
	}

	cout << a[A-1][B-1] << endl;

}

int main(){
	int A, B;
	cin >> A;
	cin >> B;
	// vector<int> a;
	// for(int j = 0; j <= n; j++){
	// 	cin >> x;
	// 	a.push_back(x);
	// }
	unique(A,B);
	return 0;
}