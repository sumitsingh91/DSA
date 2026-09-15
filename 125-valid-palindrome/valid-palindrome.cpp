// class Solution {
// public:
//     bool isPalindrome(string s) {
//         if(i>=s.size()/2) return true;
//         if(s[i] != s[s.size()-i-1]) return false;

//         return f(i+1,s);
        
//     }
// };

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};