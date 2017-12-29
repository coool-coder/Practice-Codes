#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    int score;
    string name;
    // defining compare function within struct-> work as the property of the struct.
    // friend bool operator<(struct Player a, struct Player b){
    //     if(a.score != b.score)
    //        return a.score > b.score;
    //     else
    //         return a.name < b.name;
    // }
};

bool cmp(Player a, Player b){
    if(a.score != b.score)
        return a.score > b.score;
    else
        return a.name < b.name;
}



vector<Player> comparator(vector<Player> players) {
    // when cmp function is not defined within same struct (object of which is to be sorted) 
    sort(players.begin(), players.end(), cmp);

    // if not using cmp compare function and compare function defined within struct. 
    // sort(players.begin(), players.end());   
    return players;

}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
