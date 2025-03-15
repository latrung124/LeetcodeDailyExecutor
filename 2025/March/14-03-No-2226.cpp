#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumCandies(std::vector<int> &candies, long long k) {
        using ll = long long;
        ll left = 1;
        ll right = *std::max_element(candies.begin(), candies.end());
        int result = 0;

        while (left <= right) {
            ll mid = left + (right - left) / 2;
            ll count = 0;

            for (int candy : candies) {
                count += candy / mid; // count how many children can receive at least `mid` candies
            }

            if (count >= k) {
                result = mid; // Update result and try larger number
                left = mid + 1;
            } else {
                right = mid - 1; // Try smaller number
            }
        }

        return result;
    }
};