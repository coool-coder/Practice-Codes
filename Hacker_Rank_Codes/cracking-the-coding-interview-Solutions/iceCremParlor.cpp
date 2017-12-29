/*
Input:
The first line contains an integer, , denoting the number of trips to the ice cream parlor. The  subsequent lines describe all of Sunny and Johnny's trips to the parlor; each trip is described as follows:
1) The first line contains "money"
2) The second line contains "n"
3) The third line contains "n" space-separated integers denoting the cost of each respective flavor.
The "ith" integer corresponds to the cost,"costi", for the ice cream with ID number "i" (where 1<=i<=n).

Output:
Print two space-separated integers denoting the respective ID numbers for the two distinct flavors 
they choose to purchase, where the smaller ID is printed first and the larger ID is printed second. 
Recall that each ice cream flavor has a unique ID number in the inclusive range from "1" to "flavors".
*/

#include <bits/stdc++.h>

using namespace std;

void solve(vector <int> arr, int money) {
    // using hash table
    map<int, int> hash_map1;
    map<int, int> hash_map2;
    int n = arr.size();

    for(int i = 0; i < n; i++){
        hash_map1[i+1] = arr[i];
        hash_map2[arr[i]] = i+1;
    }

    int id1, id2;
    for(int j = 0; j < n; j++){
        if(hash_map2.find(abs(money-hash_map1[j+1])) != hash_map2.end()){
            id1 = j+1;
            id2 = hash_map2[abs(money-hash_map1[j+1])];
            break;
        }
    }

    cout << id1 << " " << id2 << endl;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int money;
        cin >> money;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        solve(arr, money);
    }
    return 0;
}
