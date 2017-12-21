#include <stdio.h>
void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
void sort(int list[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                swap(&list[j], &list[j + 1]);
            }
        }
    }
}

int main() {
    int list[] = { 12, 24, 3, 11 };
    sort(list, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d\n", list[i]);
    }
    return 0;
}
