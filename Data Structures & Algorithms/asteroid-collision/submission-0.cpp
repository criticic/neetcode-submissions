class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {

            while (!st.empty() && a < 0 && st.top() > 0) {

                // current asteroid is bigger
                if (abs(a) > st.top()) {
                    st.pop();
                }

                // stack asteroid is bigger
                else if (abs(a) < st.top()) {
                    a = 0;
                }

                // both equal
                else {
                    st.pop();
                    a = 0;
                }
            }

            // if current asteroid survived
            if (a != 0) {
                st.push(a);
            }
        }

        vector<int> res(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};