class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }

private:
    int dfs(vector<int>& nums, int index, int currentXor) {
        // Base case: all elements processed
        if (index == nums.size()) {
            return currentXor;
        }

        // Include current element in subset
        int include = dfs(nums, index + 1, currentXor ^ nums[index]);

        // Exclude current element from subset
        int exclude = dfs(nums, index + 1, currentXor);

        return include + exclude;
    }
};