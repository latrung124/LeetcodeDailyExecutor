#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int result = 0;
        unordered_map<char, int> hash;

        for (int right = 0; right < s.size(); ++right) {
            ++hash[s[right]];
            while (hash['a'] > 0 && hash['b'] > 0 && hash['c'] > 0) {
                result += s.size() - right;
                --hash[s[left]];
                ++left;
            }
        }

        return result;
    }
};