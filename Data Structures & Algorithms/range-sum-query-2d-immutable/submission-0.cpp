class NumMatrix {
private:
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefixSum = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for (int r = 0; r < rows; r++) {
            int prefix = 0;
            for (int c = 0; c < cols; c++) {
                prefix += matrix[r][c];
                int above = prefixSum[r][c + 1];
                prefixSum[r + 1][c + 1] = prefix + above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        int bottomRight = prefixSum[row2][col2];
        int above = prefixSum[row1 - 1][col2];
        int left = prefixSum[row2][col1 - 1];
        int topLeft = prefixSum[row1 - 1][col1 - 1];
        return bottomRight - above - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */