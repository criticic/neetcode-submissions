class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> freqS;
        unordered_map<char, int> freqT;
        for (int i = 0; i < s.size(); i++) {
            freqS[s[i]]++;
            freqT[t[i]]++;
        }
        return freqS == freqT;
    }
};
