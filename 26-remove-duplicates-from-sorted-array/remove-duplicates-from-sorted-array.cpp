// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
        
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int i = 0; // Pointer for the last unique element placement
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j]; // Move the new unique element forward
            }
        }
        
        return i + 1; // Length of unique elements
    }
};