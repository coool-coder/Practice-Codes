#include <stdio.h>

int search(int list[], int n, int key) {
    int mid, low = 0, high = n - 1;

    while (low <= high) {
		mid = (low + high) / 2;
		if (list[mid] == key) {
			return mid;
		}
		if (key < list[mid]) {
			high = mid - 1;
		} else {
	    low = mid + 1;
		}
    }
    return -1;
}

int main() {

    int list[6] = { 11, 22, 33, 44, 55, 66 };
    int key = 55;
    int index;

    if ((index = search(list, 6, key)) == -1) {
		printf("Not found.\n");
    } else {
		printf("Found at index = %d\n", index);
    }
    return 0;
}
