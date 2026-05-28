class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;

        dfs(nums, 0, cur, ans);

        return ans;
    }
private:
    void dfs(vector<int>& nums, int index,vector<int>& cur, vector<vector<int>>& ans) {
        // Base case: all elements processed
        if (index == nums.size()) {
            ans.push_back(cur);
            return;
        }

        // Take current element
        cur.push_back(nums[index]);
        dfs(nums, index + 1, cur, ans);

        // Don't take current element
        cur.pop_back();
        dfs(nums, index + 1, cur, ans);
    }
};
