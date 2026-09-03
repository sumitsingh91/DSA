// class Solution {
// public:
//     bool isValid(string s) {
        
//     }
// };
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        // Quick check: valid parenthesis strings must have an even length
        if (s.length() % 2 != 0) return false;

        std::stack<char> st;
        std::unordered_map<char, char> matching_bracket = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            // If it's a closing bracket
            if (matching_bracket.count(c)) {
                // Return false if stack is empty or top doesn't match
                if (st.empty() || st.top() != matching_bracket[c]) {
                    return false;
                }
                st.pop();
            } else {
                // If it's an opening bracket, push onto stack
                st.push(c);
            }
        }

        // Valid only if all opened brackets were closed
        return st.empty();
    }
};