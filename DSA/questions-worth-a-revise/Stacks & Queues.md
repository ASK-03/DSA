### [Basic Calculator](https://leetcode.com/problems/basic-calculator/)
- Great use of stack, we are basically mimicking what a recursive solution would look like. as we are going into a bracket `(` we are making sure to store the current state and move forward fresh and whenever we are facing `)` we are adding the previous state to the current state * sign. 
- This is how a call stack would work. I can learn how to save state without recursion in stack from this.

```cpp
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int num = 0;
        int sign = 1;
        int res = 0;
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '+' || s[i] == '-') {
                res += sign * num;
                sign = (s[i] == '+') ? 1 : -1;
                num = 0;
            } else if (s[i] == '(') {
                st.push({res, sign});
                res = 0;
                sign = 1;
                num = 0;
            } else if (s[i] == ')') {
                res += sign * num;     
                res = st.top().first + st.top().second * res;
                st.pop();
                num = 0;
                sign = 1;
            }
        }

        return res + sign * num;
    }
};
```
