#include <iostream>
#include <climits>

using namespace std;

class minHeap{
	private:
		int *arr;
		int heapSize;
		int capacity;

	public:
		minHeap(int cap);

		int left(int i) {return 2*i+1;}
		int right(int i) {return 2*i+2;}
		int parent(int i) {return (i-1)/2;}

		void insertKey(int ele);
		int extractMin();
		//int deleteKey();
		int getMin(){return arr[0];}
		void minHeapify(int i);
		int getCount(){return heapSize;}

		void printHeap();
};

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

minHeap::minHeap(int cap){
    heapSize = 0;
    capacity = cap;
    arr = new int[cap];
}

void minHeap::insertKey(int ele){
	if(heapSize == capacity){
		cout << "overflow: can't insert\n";
		return;
	}

	heapSize++;
	int i = heapSize - 1;
	arr[i] = ele;

	while(i != 0 && arr[parent(i)] > arr[i]){
		swap(&arr[i], &arr[parent(i)]);
		i = parent(i);
	}
}

int minHeap :: extractMin(){
	if(heapSize <= 0){
		return INT_MAX;
	}
	if(heapSize == 1){
		heapSize--;
		return arr[0]; 
	}


	int root = arr[0];
	arr[0] = arr[heapSize-1];
	heapSize--;
	minHeapify(0);

	return root;
}

void minHeap :: minHeapify(int i){

	int l = left(i);
	int r = right(i);
	int smallest = i;

	if(l < heapSize && arr[l] < arr[i])
		smallest = l;

	if(r < heapSize && arr[r] < arr[smallest])
		smallest = r;

	if(smallest != i){
		swap(&arr[i], &arr[smallest]);
		minHeapify(smallest);
	}
}

void minHeap::printHeap(){
	for(int i = 0; i< heapSize; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

// int main(){
// 	minHeap *M = new minHeap(11);
// 	M->insertKey(4);
// 	M->insertKey(2);
// 	M->insertKey(5);
// 	M->insertKey(8);
// 	M->insertKey(7);
// 	M->insertKey(3);

// 	cout << M->getMin() << endl;

// 	M->printHeap();


// 	return 0;
// }