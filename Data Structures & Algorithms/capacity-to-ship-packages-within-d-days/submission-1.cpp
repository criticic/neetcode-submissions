class Solution {
    bool check(vector<int>& weights, int days, int capacity) {
        int neededDays = 1;
        int currentLoad = 0;

        for (int weight : weights) {
            if (weight > capacity) {
                return false;
            }

            if (currentLoad + weight <= capacity) {
                currentLoad += weight;
            } else {
                neededDays++;
                currentLoad = weight;
            }
        }

        return neededDays <= days;
    }

   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(weights, days, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};