class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int res = 0;
        for (const string& op : ops) {
            if (op == "+") {
                int first = st.top();
                st.pop();

                int second = st.top();

                st.push(first);

                int score = first + second;
                st.push(score);

                res += score;
            } else if (op == "D") {
                st.push(2 * st.top());
                res += st.top();
            } else if (op == "C") {
                res -= st.top();
                st.pop();
            } else {
                st.push(stoi(op));
                res += st.top();
            }
        }
        return res;
    }
};