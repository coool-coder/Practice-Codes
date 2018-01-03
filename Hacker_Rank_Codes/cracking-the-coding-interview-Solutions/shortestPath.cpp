/*
input:
2   (test cases)
1st query
4 2 (no. of nodes = 4, no of edges = 2)
1 2 (edge between 1 and 2)
1 3 (edge between 1 and 3) 
1   (starting node from where we need to shortest distance to every node)
2nd query
3 1
2 3
2

output:
6 6 -1
-1 6
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Graph {
    private:
        int noOfNodes;
        int adj[10000][10000];
    public:
        Graph(int n) {
            noOfNodes = n;
            adj[n][n] = {0};
        }
    
        void add_edge(int u, int v) {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    
        vector<int> shortest_reach(int start) {
            int visited[noOfNodes] = {0};
            vector<int> wt(noOfNodes, 0);
            queue<int> q;
            int count;
            q.push(start);
            int temp;
            // wt[start] = -1;
            while(!q.empty()){
                temp = q.front();
                count = wt[temp];
                q.pop();
                if(visited[temp] != 1){
                    count++;
                    visited[temp] = 1;
                    for(int i = 0; i < noOfNodes; i++){
                        if(adj[temp][i] == 1 && visited[i] != 1 && wt[i] < 1){
                            q.push(i);
                            wt[i] = count;
                        }
                    }
                }
            }
            return wt;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph *graph = new Graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph->add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph->shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if((distances[i] == 0) && (i != startId))
                cout << -1 << " ";
            else if (i != startId) {
                cout << distances[i]*6 << " ";
            }
        }
        cout << endl;
        // delete graph;
    }
    
    return 0;
}
