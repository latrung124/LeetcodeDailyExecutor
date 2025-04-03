#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<int> maxPrefix(n, 0);
        maxPrefix[0] = nums[0];

        // Compute maxPrefix[i] (max value from 0 to i)
        for (int i = 1; i < n; i++) {
            maxPrefix[i] = max(maxPrefix[i - 1], nums[i]);
        }

        long long maxTripletValue = 0;
        int maxSuff = nums[n - 1];

        // Iterate `j` and update `maxSuffix[k]` dynamically
        for (int j = n - 2; j > 0; j--) {
            maxSuff = max(maxSuff, nums[j + 1]); // Track max value after j
            long long leftTerm = maxPrefix[j - 1] - nums[j];
            maxTripletValue = max(maxTripletValue, leftTerm * maxSuff);
        }

        return maxTripletValue;
    }
};