// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//     }
// };

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // dp initialized with the last row of the triangle
        vector<int> dp = triangle.back();
        
        // Process bottom-up starting from the second-to-last row
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                // Minimum sum to reach bottom from current position
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }
        
        return dp[0];
    }
};