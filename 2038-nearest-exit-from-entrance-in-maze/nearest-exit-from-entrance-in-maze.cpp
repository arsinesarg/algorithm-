class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<tuple<int,int,int>> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';
        
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while (!q.empty()) {
            auto [r, c, steps] = q.front();
            q.pop();
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (maze[nr][nc] == '+') continue;
                
                if (nr == 0 || nr == m-1 || nc == 0 || nc == n-1)
                    return steps + 1;
                
                maze[nr][nc] = '+';
                q.push({nr, nc, steps + 1});
            }
        }
        return -1;
    }
};