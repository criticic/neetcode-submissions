class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for (auto i: nums) {
            frequency[i]++;
        }

        int mx = 0;
        int ans = 0;

        for (auto it : frequency) {
            if (it.second > mx) {
                mx = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};