//Given an n x m matrix, find and print the number of cells in the largest region in the matrix. 
//Note that there may be more than one region in the matrix.

#include <bits/stdc++.h>

using namespace std;

int get_biggest_region(vector< vector<int> > &grid, int row, int col){
    
    // cout << grid.size() << " " << grid[0].size() << endl;
	if((row < 0) || (col < 0) || (row >= grid.size()) || (col >= grid[0].size()))
		return 0;

    if(grid[row][col] == 0)
    	return 0;

    int count = 1;
    grid[row][col] = 0;	
    for(int r = row - 1; r <= row + 1; r++){
    	for(int c = col - 1; c <= col + 1; c++){
    		if(r != row || c != col)
    			count += get_biggest_region(grid, r, c);
    	}
    }
    return count;

}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0; grid_i < n; grid_i++){
       for(int grid_j = 0; grid_j < m; grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    // int visited[n][m] = {0};
    int maxCount = 0;
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(grid[i][j] == 1){
    			int count = get_biggest_region(grid, i, j);
    			maxCount = max(count, maxCount);
    		}
    	}
    }

    cout << maxCount << endl;
    return 0;
}