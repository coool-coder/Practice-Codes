#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    int k = 0;
    // vector<char> str;
    char str[100000] = "";
    while(n > 0){
        int rem = n%2;
        n = n/2;
        // str.push_back(char(char(rem)+'0'));
        str[k++] = char(char(rem)+'0');
    }
 
    int count = 0;
    int max = 0;
    int i = 0;
    while(i < k){
        if(str[i] == '0'){
            if(max < count)
                max = count;
            count = 0;
            i++;
        }
        else if(str[i] == '1'){
            count += 1;
            i++;
        }
    }
    if(max < count)
        max = count;
    cout << max << endl;
    return 0;
}
