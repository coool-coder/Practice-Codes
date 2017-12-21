#include <stdio.h>
void sort(int list[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (list[j] > list[i]) {
                int temp = list[i];
                int k;
                for (k = i; k > j; k--){
                    list[k] = list[k - 1];
                }
            list[k] = temp;
            }
        }
    }
}

int main() {
    int list[] = { 11, 7, 12, 3, 9 };
    sort(list, 5);
    for (int i = 0; i < 5; i++) {
	printf("%d\n", list[i]);
    }
    return 0;
}
