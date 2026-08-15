// class Solution {
// public:
//     int mySqrt(int x) {
        
//     }
// };

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 1, right = x / 2;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Use division (x / mid) instead of multiplication (mid * mid) 
            // to avoid 32-bit signed integer overflow
            if (mid <= x / mid) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};