#include <stdio.h>
#include <math.h>

int **initialization(int (*a)[100], int n){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = 0;
}

int main(){
	int n;
	scanf("%d", &n);
	// printf("#%f\n", ceil(-1.33));
	// printf("*%d\n", (-5)%n);
	int a[n][n];
	initialization(a, n);
	printf("%d\n", sizeof(a)/sizeof(int));
	int i = 0, j = n/2;
	a[i][j] = 1;
	int temp = a[i][j];
	int count = 1;
	while (count < n*n){
		printf("i = %d j = %d\n", i,j);	
		if(i-1 < 0 && j+1 == n){
			i = i+1;
			a[i][j] = temp + 1;
		}
		else if(i-1 < 0 && j+1 < n && j+1 >= 0){
			i = (i-1)%n;
			j = j+1;
			printf("#i = %d #j = %d\n", -1%n,j);	
			a[i][j] = temp + 1;
		}
		else if(j+1 >= n && i-1 < n && i-1 >= 0){
			j = (j+1)%n;
			i = (i-1);
			a[i][j] = temp + 1;
		}
		else if(a[i-1][j+1] > 0){
			i = i+1;
			a[i][j] = temp + 1;
		}
		else{
			i = i-1;
			j = j+1;
			a[i][j] = temp + 1;
		}
		temp = a[i][j];
		count += 1;
	}

	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

}
