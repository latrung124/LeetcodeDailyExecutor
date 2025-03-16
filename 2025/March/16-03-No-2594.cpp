#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long repairCars(std::vector<int> &ranks, int cars) {
        using ll = long long;

        ll min_rank = *std::min_element(ranks.begin(), ranks.end());
        ll left = 1;
        ll right = min_rank * (ll)cars * cars;
        ll result = right;

        auto canRepair = [&](ll time) -> bool {
            ll totalcars = 0;
            for (int rank : ranks) {
                totalcars += std::sqrt(time / rank);
                if (totalcars >= cars) {
                    return true;
                }
            }
            return false;
        };

        while (left < right) {
            ll mid = left + (right - left) / 2;
            if (canRepair(mid)) {
                result = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};