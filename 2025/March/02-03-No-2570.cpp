#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int temp1 = 0, temp2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        
        // Merge elements from both lists until one is exhausted.
        while (temp1 < n1 && temp2 < n2) {
            if (nums1[temp1][0] == nums2[temp2][0]) {
                // Both arrays have the same id.
                // Sum their values and add to the answer.
                ans.push_back({nums1[temp1][0], nums1[temp1][1] + nums2[temp2][1]});
                temp1++;
                temp2++;
            } else if (nums1[temp1][0] < nums2[temp2][0]) {
                // The current id in nums1 is smaller.
                // Add the pair from nums1 to the answer.
                ans.push_back({nums1[temp1][0], nums1[temp1][1]});
                temp1++;
            } else {
                // The current id in nums2 is smaller.
                // Add the pair from nums2 to the answer.
                ans.push_back({nums2[temp2][0], nums2[temp2][1]});
                temp2++;
            }
        }
        
        // If any elements remain in nums1, add them.
        while (temp1 < n1) {
            ans.push_back({nums1[temp1][0], nums1[temp1][1]});
            temp1++;
        }
        
        // If any elements remain in nums2, add them.
        while (temp2 < n2) {
            ans.push_back({nums2[temp2][0], nums2[temp2][1]});
            temp2++;
        }
        
        return ans;
    }
};