#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);
        vector<int> result;
        
        // Step 1: Store last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        // Step 2: Partitioning logic
        int maxLast = 0, prev = -1;
        for (int i = 0; i < s.size(); i++) {
            maxLast = max(maxLast, lastIndex[s[i] - 'a']);
            if (i == maxLast) {
                result.push_back(i - prev);
                prev = i;
            }
        }

        return result;
    }
};
