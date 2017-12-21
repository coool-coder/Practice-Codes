#include <iostream>
#include <cstdio>

using namespace std;

int maxArr(vector<int> &A) {
    int max_diff=0, f;
    for (int i=1;i<=A.size();i++){
        for (int j=i+1; j<=A.size(); j++){
            f = abs(A[i-1]-A[j-1]) + abs(i-j);
            if (f > max_diff){
                max_diff = f;
            }
        }
    }
    return max_diff;
}

int main(){
    //A = [1, 3,-1];
    vector<int> v;
    int x = maxArr ()
}
|aj-ai| + j-i

aj-ai + j-i=aj+j- (ai+i)
ai-aj + j-i =ai-i -(aj-j)

ai + i
ai - i


4 6 7 3 8
minm