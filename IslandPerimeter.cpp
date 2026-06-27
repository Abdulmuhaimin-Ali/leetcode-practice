// Island Perimeter

class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int islandPerimeter(vector<vector<int>>& grid) {
        
        int edgeCount = 0;

        queue<pair<int,int>> q;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i =0; i < grid.size(); i++){

            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    q.push({i, j});
                }
                visited[i][j] = true;

                while(!q.empty()){
                    pair<int, int> curr = q.front();
                    q.pop();
                    q.size();

                    // horizonatal and diagonal
                    for(auto dir : directions){
                        int newRow = curr.first + dir.first;
                        int newCol = curr.second + dir.second;
                        // check water edge
                        if(newRow < 0 || newRow == grid.size() || newCol < 0 || newCol == grid[0].size()){
                            edgeCount++;

                        }
                        else if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 0){
                            edgeCount++;
                        }

                        // add island to bfs
                        if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && visited[newRow][newCol] == false && grid[newRow][newCol] == 1){
                           q.push({newRow, newCol});
                           visited[newRow][newCol] = true;
                        }
                    }
                }
            }
        }

        return edgeCount;
    }
};