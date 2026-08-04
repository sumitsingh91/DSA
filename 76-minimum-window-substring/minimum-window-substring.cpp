// class Solution {
// public:
//     string minWindow(string s, string t) {
        
//     }
// };
#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequency map for characters in t
        std::vector<int> target_freq(128, 0);
        for (char c : t) {
            target_freq[c]++;
        }

        // Frequency map for current window in s
        std::vector<int> window_freq(128, 0);

        int required_chars = 0;
        for (int count : target_freq) {
            if (count > 0) required_chars++;
        }

        int formed_chars = 0;
        int left = 0, right = 0;
        
        // Stores the length of min window and its starting index
        int min_len = INT_MAX;
        int min_start = 0;

        while (right < s.length()) {
            char c = s[right];
            window_freq[c]++;

            // Check if frequency of current character matches target frequency
            if (target_freq[c] > 0 && window_freq[c] == target_freq[c]) {
                formed_chars++;
            }

            // Try to shrink window from left if all characters are covered
            while (left <= right && formed_chars == required_chars) {
                c = s[left];

                // Update minimum window length
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }

                // Remove character at left pointer from window
                window_freq[c]--;
                if (target_freq[c] > 0 && window_freq[c] < target_freq[c]) {
                    formed_chars--;
                }

                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};