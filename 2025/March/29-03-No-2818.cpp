#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n), score(n, 0);
        vector<pair<int, int>> numIndex; // Store {num, index}

        // Step 1: Compute the score for each number (count of distinct prime factors)
        for (int i = 0; i < n; i++) {
            numIndex.emplace_back(nums[i], i);
            score[i] = countPrimeFactors(nums[i]);
        }

        // Step 2: Find left and right boundaries for maximum score subarrays
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && score[st.back()] < score[i]) {
                right[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && score[st.back()] <= score[i]) {
                left[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }

        // Step 3: Sort nums in descending order with index mapping
        sort(numIndex.rbegin(), numIndex.rend());

        // Step 4: Compute the maximum score using the largest numbers first
        long long ans = 1;
        const int MOD = 1e9 + 7;

        for (const auto& [num, idx] : numIndex) {
            if (k <= 0) break;
            long long count = (idx - left[idx]) * 1LL * (right[idx] - idx);
            long long take = min(k * 1LL, count);
            ans = (ans * modPow(num, take, MOD)) % MOD;
            k -= take;
        }
        return ans;
    }

private:
    // Function to count distinct prime factors
    int countPrimeFactors(int num) {
        int count = 0;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                count++;
                while (num % i == 0) num /= i;
            }
        }
        if (num > 1) count++; // If num is still > 1, it's a prime factor
        return count;
    }

    // Modular exponentiation (base^exp % mod)
    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
};
