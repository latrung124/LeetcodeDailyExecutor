#include <vector>

using namespace std;

class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            return dfs(nums, 0, 0);
        }
        
        int dfs(vector<int>& nums, int index, int currentXor) {
            if (index == nums.size()) {
                return currentXor;
            }
    
            // Include nums[index] in the subset
            int withElement = dfs(nums, index + 1, currentXor ^ nums[index]);
            // Exclude nums[index] from the subset
            int withoutElement = dfs(nums, index + 1, currentXor);
    
            return withElement + withoutElement;
        }
    };
    