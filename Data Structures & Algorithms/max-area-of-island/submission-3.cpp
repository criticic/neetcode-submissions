class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    maxArea = max(maxArea, dfs(grid, row, col));
                }
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() ||
            col < 0 || col >= grid[0].size() ||
            grid[row][col] == 0) {
            return 0;
        }

        grid[row][col] = 0;

        return 1
             + dfs(grid, row + 1, col)
             + dfs(grid, row - 1, col)
             + dfs(grid, row, col + 1)
             + dfs(grid, row, col - 1);
    }
};