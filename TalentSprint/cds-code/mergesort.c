#include <stdio.h>

int arr[] = { 54, 26, 93, 17, 77, 31, 44, 55 };
void merging(int start, int mid, int end) {
    int low1;
    int low2;
    int i;
    int temp[50];
    for (low1 = start, low2 = mid + 1, i = start; low1 <= mid && low2 <= end; i++) {
        if (arr[low1] <= arr[low2]) {
            temp[i] = arr[low1++];
        } else {
            temp[i] = arr[low2++];
        }
    }
    while (low1 <= mid) {
        temp[i++] = arr[low1++];
    }
    while (low2 <= end) {
        temp[i++] = arr[low2++];
    }
    for (i = start; i <= end; i++) {
        arr[i] = temp[i];
    }
}

void sort(int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        sort(start, mid);
        sort(mid + 1, end);
        merging(start, mid, end);
    }
}

int main() {
    int n = sizeof(arr) / sizeof(int);
    sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
