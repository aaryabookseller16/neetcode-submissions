class Solution {
public:
    bool isNumber(const string& s) {
        if (s.empty()) return false;
        int i = 0;
        if (s[0] == '-' && s.size() > 1) i = 1;  // handle negative numbers
        for (; i < s.size(); ++i) {
            if (!isdigit(s[i])) return false;
        }
        return true;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (isNumber(token)) {
                st.push(stoi(token));
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int result = 0;

                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else if (token == "/") result = a / b; // assume no div-by-zero in input

                st.push(result);
            }
        }

        return st.top();
    }
};
