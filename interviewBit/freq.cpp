//------ Counting the no. of occurence of the target element in a sorted array----- //

#include <iostream>
#include <stdio.h>
#include <vector>


using namespace std;

int BinarySearch(vector<int> arr, int n, int element, bool searchElement){
	int low=0, high=n-1, result=-1; 
	while (low <= high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==element){
			result=mid;
			if (searchElement)
				high=mid-1;
			else
				low = mid+1;
		}
		else if(arr[mid] > element){
			high=mid-1;
		}
		else{
			low = mid+1;
		}
	}
	return result;
}

int main(){
	vector<int> v;
	int n;
	cin>>n;
	int x;
	for(int i=0; i<n; i++){
		cin>>x;
		v.push_back(x);
	}
	int element;
	cin >> element;
	int low_index = BinarySearch(v, n, element, 1);
	int high_index = BinarySearch(v, n, element, 0);
	printf("freq: %d\n", high_index - low_index + 1);
}
