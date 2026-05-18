class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> needMap; // value, index
        for (int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            if (needMap.find(need) != needMap.end()) {
                return {needMap[need], i};
            }
            needMap.insert({nums[i], i});
        }
        return {};
    }
};
