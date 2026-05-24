class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size() - 1;
        int boats = 0;

        while (left <= right) {
            // add the heaviest first
            int remaining = limit - people[right];
            right--;
            boats++;

            // add lighter one if space
            if (left <= right && people[left] <= remaining) {
                left++;
            }
        }

        return boats;
    }
};