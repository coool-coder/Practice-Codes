#include <stdio.h>
#include <string.h>

int main(){
	int n;
	int m;
	int result = 0;

	scanf("%d %d", &m, &n);

	while(m > 0){
		printf("%d %d\n", m, n);
		if(m%2!=0){
			result = result + n;
		}

		m = m/2;
		n = n*2;
	}

	printf("result = %d\n", result);

	int a[] = {17,3, 8};
	int* p = a +3;
	printf("%d", p[-1]);
	return 0;

}
