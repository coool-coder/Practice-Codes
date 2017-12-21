#include <stdio.h>
#include <stdlib.h>
// #include "circular_queue.c"

void josephus(int n, int k){
	int a[n];
	for(int i = 0; i < n; i++){
		a[i]=i+1;
	}


	int i = k%n;
	
	for(int iter = n; iter > 1; i=(i+k-1)%n){
		printf("%d ",a[i-1]);
		if (a[i]==0){
			i+=1;
			while(a[i] == 0){
				i=(i+1)%n;
			} 
		}
		int count =1;
		while(count <= k){
			if(a[i-1] != 0){
				a[i-1] = 0;
				i+=1;
				count++;
			}
		}
		iter = iter-1;

	}
	printf("\n");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(){
	int n,k;
	scanf("%d %d", &n, &k);
	josephus(n, k);
	// cqueue_t Q1 = {n, -1, -1};

	// for(int i = 1; i <= n; i++){
	// 	enqueue(&Q1, i);
	// }



	return 0;
}