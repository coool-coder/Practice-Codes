#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	// int a[(2*n-1)*(2*n-1)]={0};
	vector<vector<int> > matrix(2*n-1);
    for ( int i = 0 ; i < 2*n-1 ; i++ )
        matrix[i].resize(2*n-1);
    int i=0, m=0;
	for(i=0; i<n; i++){
		m=0;
		for(int j=0; j<i; j++){
			// printf("%d ", n-j);
			matrix[i][m] = n-j;
			m++;
		}

		for(int j=i; j<2*n-1-i; j++){
			// printf("%d ", n-i);
			matrix[i][m] = n-i;
			m++;
		}
		
		for(int j=i;j>0;j--){
			// printf("%d ", n-j+1);
			matrix[i][m] = n-j+1;
			m++;
		}
		// printf("\n");
	}
	int l=i;
	for(int i=n-1; i>0;i--){
		m=0;
		for(int j=0;j<i-1;j++){
			// printf("%d ", n-j);
			matrix[l][m] = n-j;
			m++;
		}
		for(int j=2*(n-i)+1; j>0; j--){
			// printf("%d ",n-i+1);
			matrix[l][m] = n-i+1;
			m++;
		}
		
		for(int j=i-1; j>0; j--){
			// printf("%d ", n-j+1);
			matrix[l][m] = n-j+1;
			m++;
		}
		l++;
		// printf("\n");
	}
	int RR=2*n-1;
	for(int i=0;i<RR;i++){
        for(int j=0;j<RR;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

