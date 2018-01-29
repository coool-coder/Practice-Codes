#include <bits/stdc++.h>

using namespace std;

int sqrt(int A) {
    if(A == 1){
        return 1;
    }
    int curr = A/2;
    int last = A;
    int first = 0;
    while(1){
        if(pow(curr, 2) <= A && pow(curr+1, 2) > A){
            return floor(curr);
        }
        else if(pow(curr,2) > A){
            last = curr;
            curr = (first + curr)/2;
        }
        else if(pow(curr,2) < A){
            first = curr;
            curr = (curr + last)/2;
        }
            
    }
}

int main(){
    int A;
    cin >> A;
    cout << sqrt(A) << endl;
    // cout << 3/2 << endl;
 
   return 0;
}