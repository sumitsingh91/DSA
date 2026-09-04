// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
        
//     }
// };
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the array from right to left (least significant to most)
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // No carry over, we are done
            }
            digits[i] = 0; // If current digit is 9, it turns to 0 and carries over
        }
        
        // If all digits were 9 (e.g., 999 -> 000), insert a 1 at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};