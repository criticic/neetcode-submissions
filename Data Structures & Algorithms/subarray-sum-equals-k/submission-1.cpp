class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;

        // prefix sum 0 exists once before starting
        prefixCount[0] = 1;

        int currentSum = 0;
        int answer = 0;

        for (int num : nums) {
            currentSum += num;

            // We want:
            // currentSum - previousSum = k
            int neededPrefix = currentSum - k;

            // If such a prefix existed before,
            // then we found valid subarrays
            if (prefixCount.find(neededPrefix) != prefixCount.end()) {
                answer += prefixCount[neededPrefix];
            }

            // Store current prefix sum
            prefixCount[currentSum]++;
        }

        return answer;
    }
};