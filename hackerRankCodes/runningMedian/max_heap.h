#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
using namespace std;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

class maxHeap{
private:
	int *arr;
	int heapSize;
	int capacity;
public:
	maxHeap(int cap);
	int parent(int i){return (i-1)/2;}
	int right(int i){return 2*i+2;}
	int left(int i){return 2*i+1;}

	int extractMax();
	int getMax(){return arr[0];}
	void insertKey(int ele);
	void maxHeapify(int i);
	int getCount(){return heapSize;}
	void printHeap();

};

maxHeap::maxHeap(int cap){
    heapSize = 0;
    capacity = cap;
    arr = new int[cap];
}

void maxHeap::insertKey(int ele){
	if(heapSize == capacity){
		cout << "overflow: can't insert\n";
		return;
	}

	int i = heapSize++;
	arr[i] = ele;

	while(i != 0 && arr[parent(i)] < arr[i]){
		swap(arr[parent(i)], arr[i]);
		i = parent(i);
	} 
}

int maxHeap::extractMax(){
	if(heapSize <= 0){
		return INT_MAX;
	}
	if(heapSize == 1)
		return arr[0];

	int root = arr[0];
	arr[0] = arr[--heapSize];

	maxHeapify(0);
	return root;
}

void maxHeap :: maxHeapify(int i){
	int largest = i;
	int lt = left(i);
	int rt = right(i);

	if(lt < heapSize && arr[lt] > arr[i])
		largest = lt;

	if(rt < heapSize && arr[rt] > arr[largest])
		largest = rt;

	if(largest != i){
		swap(arr[i], arr[largest]);
		maxHeapify(largest);
	}

}

void maxHeap::printHeap(){
	for(int i = 0; i < heapSize; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

// int main(){
// 	maxHeap M(10);

// 	M.insertKey(4);
// 	M.insertKey(8);
// 	M.insertKey(2);
// 	M.insertKey(10);
// 	M.insertKey(11);
// 	M.insertKey(12);

// 	cout << M.getMax() << endl;
// 	M.printHeap();	

// 	return 0;	
// }