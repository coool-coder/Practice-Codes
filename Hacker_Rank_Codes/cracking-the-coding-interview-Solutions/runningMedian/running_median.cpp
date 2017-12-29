#include <iostream>
#include <cstdio>
#include <vector>
#include "min_heap.h"
#include "max_heap.h"
#include <iomanip>

using namespace std;

double getMedian(int v, double med, minHeap &min_, maxHeap &max_){
	int n1 = min_.getCount();
	int n2 = max_.getCount();
	if(n1 == n2){
		if(v > med){
			min_.insertKey(v);
			med = min_.getMin();
		}
		else{
			max_.insertKey(v);
			med = max_.getMax();
		}
	} 
	else if(n1 > n2){
		if(v > med){
			max_.insertKey(min_.extractMin());
			min_.insertKey(v);
		}else{
			max_.insertKey(v);
		}
		med = (max_.getMax() + min_.getMin())/2.0;
	}
	else{
		 	
		if(v > med){
			min_.insertKey(v);
		}else{
			min_.insertKey(max_.extractMax());
			max_.insertKey(v);
		}
		med = (max_.getMax() + min_.getMin())/2.0;

	}
	return med;
}

int main(){
	int n;
	cin >> n;
	vector<int> v;
	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	} 

	minHeap *min_ = new minHeap(1000);
	maxHeap *max_ = new maxHeap(1000);
	double med = 0.0;
	for(int i = 0; i < n; i++){
		med = getMedian(v[i], med, *min_, *max_);
		cout << fixed << setprecision(1) << med << endl;
	}
	return 0;
}