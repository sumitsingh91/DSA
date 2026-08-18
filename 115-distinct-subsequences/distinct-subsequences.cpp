// class Solution {
// public:
//     int numDistinct(string s, string t) {
        
//     }
// };

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        // Base case: dp[0] = 1 (empty string target can always be formed once)
        // Using unsigned long long to handle potential intermediate overflow before capping
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; ++i) {
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};