// C++ program to find a triplet
# include <bits/stdc++.h>
using namespace std;
 
// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
int find3Numbers(vector<int> A, int arr_size, int sum)
{
    int l, r;
 
    /* Sort the elements */
    sort(A.begin(), A.end());
    for(int i = 0; i < A.size(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
 
    /* Now fix the first element one by one and find the
       other two elements */
    int diff = INT_MAX;

    int res = 0;
    for (int i=0; i<arr_size-2; i++)
    {
 
        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        l = i + 1; // index of the first element in the
                   // remaining elements
        r = arr_size-1; // index of the last element
        while (l < r)
        {
            int tempSum = A[i] + A[l] + A[r];
            cout << A[i] << " + " << A[l] << " + " << A[r] << " = " << tempSum << endl;
            cout << "res: " << res << " diff: " << diff << endl;
            if( tempSum == sum)
            {
                printf("Triplet is %d, %d, %d", A[i], 
                                         A[l], A[r]);
                return sum;
            }
            else if (tempSum < sum){
                if(abs(sum - tempSum) < diff){
                    diff = abs(sum - tempSum);
                    res = tempSum;
                }
                l++;
            }
            else{
                if(abs(sum - tempSum) < diff){
                    diff = abs(sum - tempSum);
                    res = tempSum;
                }
                r--;

            }
        }
    }
 
    // If we reach here, then no triplet was found
    return res;
}

int main(){
    int m;
    cin >> m;
    vector<int> A;
    int x;
    for(int i = 0; i < m; i++){
        cin >> x;   
        A.push_back(x);
    }
    int target;
    cin >> target;
    int sum = find3Numbers(A, m, target);

    cout << sum << endl;
    return 0;
}