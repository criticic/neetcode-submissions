class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int l = 1, r = x / 2;

        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long sq = m * m;

            if (sq == x) {
                return m;
            }

            if (sq < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return r;
    }
};