class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k = 3;

        unordered_map<int, int> candidateMap;

        // First pass: find potential candidates
        for (int num : nums) {
            candidateMap[num]++;

            // If candidates exceed k-1
            if (candidateMap.size() > k - 1) {

                unordered_map<int, int> newCandidateMap;

                for (auto& entry : candidateMap) {
                    if (entry.second > 1) {
                        newCandidateMap[entry.first] = entry.second - 1;
                    }
                }

                candidateMap = newCandidateMap;
            }
        }

        // Second pass: verify actual frequencies
        unordered_map<int, int> actualCount;

        for (int num : nums) {
            if (candidateMap.count(num)) {
                actualCount[num]++;
            }
        }

        vector<int> ans;

        for (auto& entry : actualCount) {
            if (entry.second > nums.size() / k) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};