#include <stdio.h>

int search(int list[], int n, int key) {
    for (int i = 0; i < n; i++) {
		if (list[i] == key) {
			return i;
		}
	}
    return -1;
}

int main() {
	
    int list[6] = { 17, 3, 8, 24, 12, 8 };
    int key = 8;
    int index;

    if ((index = search(list, 6, key)) == -1) {
		printf("Not found.\n");
    } else {
		printf("Found at index = %d\n", index);
    }
    return 0;
}
