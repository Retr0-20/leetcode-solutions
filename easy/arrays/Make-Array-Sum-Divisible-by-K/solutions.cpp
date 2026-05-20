#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        
        int total = 0;

        for(int i = 0; i < nums.size(); i++) {
            total = total + nums[i];
        }

        return total % k;
    }
};