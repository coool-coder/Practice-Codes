#include <stdio.h>
void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int get_smallest_index(int list[], int start, int end) {
    int smallest_index = start;
    for (int i = start + 1; i <= end; i++) {
        if (list[i] < list[smallest_index]) {
            smallest_index = i;
        }
    }
    return smallest_index;
}

void sort(int list[], int n) {
    int smallest_index;
    for (int i = 0; i < n - 1; i++) {
        smallest_index = get_smallest_index(list, i + 1, n - 1);
        if (list[i] > list[smallest_index]) {
            swap(&list[i], &list[smallest_index]);
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
