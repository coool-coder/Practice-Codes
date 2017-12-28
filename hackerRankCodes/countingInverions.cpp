// eg:
// arr = [2,1,3,1,2]--swap1-->[1,2,3,1,2]--swap2-->[1,1,2,3,2]--swap1-->[1,1,2,2,3]
// As we performed a total of 1+2+1 = 4 swaps to correct inversions, we print 4 on a new line

#include <bits/stdc++.h>

using namespace std;

long merge(vector<int>& arr, int low, int mid, int high){

    long count = 0;
    int i = low, j = mid+1;
    int n = high-low+1;
    int temp[n];
    int k = 0;
    while((i <= mid) && (j <= high)){
        if(arr[i] > arr[j]){
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }

        else{
            temp[k++] = arr[i++];
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= high)
        temp[k++] = arr[j++];

    k = 0;
    for(i = low; i <= high; i++){
        arr[i] = temp[k++];
    }

    return count;
}

/*Inversion count will be sum of inversions in left-part, right-part
and number of inversions in merging */
long countInversions(vector<int>& arr, int low, int high){
    long count = 0;
    int mid;
    if(low < high){
        mid = low + (high-low)/2;
        count = countInversions(arr, low, mid);
        count += countInversions(arr, mid+1, high);
        count += merge(arr, low, mid, high);
    }
    return count;

}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        long result = countInversions(arr, 0, n-1);
        cout << result << endl;
    }
    return 0;
}