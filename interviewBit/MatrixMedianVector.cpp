#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int min = INT_MAX, max = INT_MIN;
    for(int i=0; i<m; i++){
        if(min > A[i][0]){
            min = A[i][0];
        }
    }
    for(int i=0; i<m; i++){
        if(max < A[i][n-1]){
            max = A[i][n-1];
        }
    }
    
    int required = (m*n+1)/2;
    while(min < max){
        int mid = min + (max-min)/2;
        int num=0;
        for (int i=0; i < m; i++){
            for (int j=0; j<n; j++){
                if (A[i][j] <= mid)
                    num+=1;
            }
        }

        if (num < required){
            min = mid+1;
        }
        else
            max=mid;
    }
    return min;
}

int main(){
	int RR, CC;
    int x;
    cin>>RR;
    cin>>CC;
    vector<vector<int> > matrix(RR);
    for ( int i = 0 ; i < RR ; i++ )
        matrix[i].resize(CC);

    for(int i=0; i<RR; i++){
        for(int j=0; j<CC; j++)
            cin >> matrix[i][j];
    }

    int result = findMedian(matrix);
    printf("%d\n", result);    
    // for(int i=0;i<RR;i++){
    //     for(int j=0;j<CC;j++){
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }

}
