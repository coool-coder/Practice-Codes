#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> repeatedNumber(vector<int> &A) {
    //int a[100000];
   int diff, sum=0, sq_sum=0, ActSq_sum=0;
    for (int i=1; i<=A.size(); i++){
        sum+=i;
        sq_sum+=i*i;
        ActSq_sum+= A[i-1]*A[i-1];
    }
    int Act_sum = accumulate(A.begin(), A.end(), 0);
    cout << "# " << Act_sum << endl;

    diff = (Act_sum-sum);
    int sq_diff = (ActSq_sum - sq_sum); 
    int M = (sq_diff + (diff*diff))/(2*diff);
    int N = M-diff;
    //for (int i=)    
    vector<int> B;
    B.push_back(M);
    B.push_back(N);
    
    
    return B;

    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

int main(){

    vector<int> A;
    vector<int> v;
    //for (int i=0; i<5; i++){
    A.push_back(2);
    A.push_back(2);
    //A.push_back(2);
    //A.push_back(5);
    //A.push_back(3);

    v = repeatedNumber(A);
    cout << "A = " <<v[0] << " B = " << v[1] << endl; 
    return 0;
}