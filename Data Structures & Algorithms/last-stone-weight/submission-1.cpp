class Solution {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
public:
    int lastStoneWeight(vector<int>& stones) {
        for (int s : stones) {
            maxHeap.push(s);
        }

        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            if (second < first) {
                maxHeap.push(first - second);
            }
            
            if (second > first) {
                maxHeap.push(second - first);
            }
        }

        maxHeap.push(0);
        return maxHeap.top();
    }
};
