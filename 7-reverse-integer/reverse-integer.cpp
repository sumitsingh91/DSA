// class Solution {
// public:
//     int reverse(int x) {
//         int rev = 0;
//         while(x){
//             int lastDigit = x%10;
//             x = x/10;
//             rev = (rev*10) + lastDigit;
//         }
//         return rev;
//     }
// };

#include <climits>

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        while (x != 0) {
            int lastDigit = x % 10;
            x /= 10;
            
            // Check for potential overflow/underflow before multiplying by 10
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && lastDigit > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && lastDigit < -8)) return 0;
            
            rev = (rev * 10) + lastDigit;
        }
        
        return rev;
    }
};

