class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        // Comparator for min heap
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            int distA = a[0] * a[0] + a[1] * a[1];
            int distB = b[0] * b[0] + b[1] * b[1];

            return distA > distB;
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

        // Push all points into heap
        for (const auto& point : points) {
            minHeap.push(point);
        }

        // Extract K closest points
        vector<vector<int>> result;

        for (int i = 0; i < K; i++) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        return result;
    }
};