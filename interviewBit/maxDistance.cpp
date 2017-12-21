// Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j]. If there is no solution possible, return -1

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

// int max_Distance(const vector<int> &A){
// 	int len = A.size();
// 	int max = 0;
// 	int j = 1;
// 	for(int i = 0; i < len; i++){
// 		for(int j = i+1; j < len; j++){
// 			if(A[i]<=A[j] && max < j-i){
// 				max = j-i;
// 				printf("%d - %d =  %d\n",j, i, max);
// 			}
// 		}
// 		if(max == len-i)
// 			break;
// 	}

// 	return max;
// }
int min(int a, int b){
    return (a > b) ? b:a;
} 
int max(int a, int b){
    return (a > b) ? a:b;
} 
int max_Distance(const vector<int> &A) {
    
    int len = A.size();
	int aMin[len];
	int aMax[len];
	
	aMin[0] = A[0];
	for(int i = 1; i < len; i++){
	    aMin[i] = min(A[i], aMin[i-1]);
	}
	aMax[len-1] = A[len-1];
	printf("#%d ", aMax[len-1]);
    for(int i = len-2; i >= 0; i--){
	    aMax[i] = max(A[i], aMax[i+1]);
	}
	for(int i = 0; i < len; i++){
		printf("%d ", aMin[i]);
		printf("%d \n", aMax[i]);
	}

	int i = 0; int j = 0;
	int maxDistance = 0;
	while(i < len && j < len){
	    if(aMin[i] <= aMax[j]){
	        maxDistance = max(maxDistance, j-i);
	        j++;
	    }else{
	        i++;
	    }
	}
	return maxDistance;
}

int main(){

	int n;
	cin >> n;
	vector<int> v;
	int x;
	for(int i = 0; i< n ; i++){
		cin>>x;
		v.push_back(x);
	}
	int k = max_Distance(v);
	// int k = max_Distance(v);

	cout << "max_Distance: " << k << endl;

	return 0;
}