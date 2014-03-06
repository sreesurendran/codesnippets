#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minpathsum(vector<vector<int>>& grid){

	if(grid.size() == 0)
		return 0;

	int rows = grid.size();
	int columns = grid[0].size();

	vector<int> path(columns,INT_MAX);

	path[0] = 0;

	for(int i=0;i<rows;i++){
		path[0] = path[0] + grid[i][0];
		for(int j=1;j<columns;j++){
			path[j] = min(path[j],path[j-1]) + grid[i][j];
		}
	}
	
	return path.back();
}

int main(){

	cout<<endl;
	//vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>> grid = {{4,6},{2,8}};
	cout<<endl<<"Minimum path sum:"<<minpathsum(grid);
	cout<<endl;
	return 0;

}
