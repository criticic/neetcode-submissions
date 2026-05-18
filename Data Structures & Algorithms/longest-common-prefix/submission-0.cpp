class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp;
        size_t minSize = strs[0].size();
        for (auto &s: strs) {
            minSize = min(minSize, s.size());
        }

        for (int i = 0; i < minSize; i++) {
            char c = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return lcp;
                }
            }

            lcp += c;
        }

        return lcp;
    }
};