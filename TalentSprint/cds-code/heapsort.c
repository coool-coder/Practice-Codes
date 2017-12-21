#include <stdio.h>
void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
void heapsort(int arr[], int n) {
    for (--n; n > 0; --n) {
        for (int i = n; i > 0; i--) {
            int child = i;
            while (child > 0) {
                int par = (child - 1) / 2;
                if (arr[child] > arr[par]) {
                    swap(&arr[child], &arr[par]);
                }
                child = par;
            }
        }
        swap(&arr[0], &arr[n]);
    }
}
int main() {
    int arr[] = { 12, 15, 4, 14, 7, 2 };
    int n = sizeof(arr) / sizeof(int);
    heapsort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
