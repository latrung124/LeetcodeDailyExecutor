#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Create a boolean vector for prime checking.
        vector<bool> isPrime(right + 1, true);
        if(right >= 0) isPrime[0] = false;
        if(right >= 1) isPrime[1] = false;
        
        // Sieve of Eratosthenes to mark non-prime numbers.
        for (int i = 2; i * i <= right; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i)
                    isPrime[j] = false;
            }
        }
        
        // Gather primes in the range [left, right].
        vector<int> primes;
        for (int p = left; p <= right; ++p) {
            if (isPrime[p])
                primes.push_back(p);
        }
        
        // Find the adjacent pair with the smallest difference.
        vector<int> result = {-1, -1};
        int minDiff = INT_MAX;
        for (int i = 1; i < primes.size(); ++i) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = primes[i - 1];
                result[1] = primes[i];
            }
        }
        
        return result;
    }
};