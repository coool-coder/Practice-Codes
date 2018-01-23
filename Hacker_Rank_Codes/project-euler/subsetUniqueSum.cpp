#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

void calculatingSum(int arr[], int n, int r, int index, int i, map<int, int> &m, int sum){
	if (index == r) {
		if(m.find(sum) != m.end())
			m[sum] += 1;
		else
			m[sum] = 1; 
		return;
	}

	if (i >= n)
		return;

	sum += arr[i];
	int temp = arr[i];
    calculatingSum(arr, n, r, index + 1, i + 1, m, sum);

	calculatingSum(arr, n, r, index, i + 1, m, sum-temp);
}

map<int, int> subsetFormation(int arr[], int n, int r){
	map<int, int> m;
	calculatingSum(arr, n, r, 0, 0, m, 0);

	return m;
}

int main()
{
    int n, r;
    cin >> n;
    cin >> r;
    int arr[100000];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
	map<int, int> m = subsetFormation(arr, n, r);

	map<int, int> :: iterator it;
	int sum = 0;
	for(it = m.begin(); it != m.end(); it++){
		if(it->second == 1)
			sum += it->first;
	}
	cout << sum << endl;

	return 0;
}
