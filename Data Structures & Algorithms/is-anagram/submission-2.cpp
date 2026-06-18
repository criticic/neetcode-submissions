class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        sort(t.begin(), t.end());
        sort(s.begin(), s.end());

        return s == t;
    }
};
