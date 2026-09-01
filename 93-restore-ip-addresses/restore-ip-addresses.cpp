// class Solution {
// public:
//     vector<string> restoreIpAddresses(string s) {
        
//     }
// };

#include <vector>
#include <string>

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        // Optimization: valid IP lengths must be between 4 and 12 characters
        if (s.length() < 4 || s.length() > 12) return result;
        
        backtrack(s, 0, 0, "", result);
        return result;
    }

private:
    void backtrack(const string& s, int startIdx, int dots, string currentIP, vector<string>& result) {
        // Base Case: 4 segments placed
        if (dots == 4) {
            if (startIdx == s.length()) {
                // Remove trailing dot before saving
                currentIP.pop_back(); 
                result.push_back(currentIP);
            }
            return;
        }

        // Try candidate segments of length 1, 2, and 3
        for (int len = 1; len <= 3; ++len) {
            if (startIdx + len > s.length()) break;

            string segment = s.substr(startIdx, len);

            // Rule 1: No leading zeros allowed for multi-digit segments
            if (segment.length() > 1 && segment[0] == '0') break;

            // Rule 2: Segment value must be <= 255
            if (stoi(segment) > 255) break;

            // Recurse to the next segment
            backtrack(s, startIdx + len, dots + 1, currentIP + segment + ".", result);
        }
    }
};