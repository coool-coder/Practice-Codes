#include<stdio.h>
int list[] = { 17, 3, 8, 24, 12, 19 };

void swap(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

void split(int low, int high, int *partition) {

	int pivot;
	int i;
	int j;

	pivot = list[low];
	i = low;
	j = high;
	while (i < j) {
		while (list[i] <= pivot && i < j) {
			i++;
		}
		while (list[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap(&list[i], &list[j]);
		}
	}

	*partition = j;
	swap(&list[low], &list[j]);
}

void quick(int low, int high) {
	int partition;
	if (low < high) {
		split(low, high, &partition);
		quick(low, partition - 1);
		quick(partition + 1, high);
	}
}

int main() {
	quick(0, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d\n", list[i]);
	}
	return 0;
}
