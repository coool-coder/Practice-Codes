//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).
//You are given a target value to search. If found in the array, return its index, otherwise return -1. 
//You may assume no duplicate exists in the array.

int funct(vector<int> A, int B){
	int low = 0;
    int high = A.size() - 1; 
    while(low <= high){
        int mid = (low + high)/2;
        if (A[mid] == B) return mid;
        
        if (A[low] <= A[mid]){
            if (B >= A[low] && B <= A[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }   
        else if (B >= A[mid] && B <= A[high])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
	cin >> B;
	vector<int> a;
	for(int j = 0; j <= n; j++){
		cin >> x;
		a.push_back(x);
	}
	funct(a, B);
}