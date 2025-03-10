#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        
        // Set of vowels for quick lookup
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        // Map to keep track of vowel counts in the current window
        std::unordered_map<char, int> vowelCount;

        // Count of consonants in the current window
        int cons = 0;
        
        // Left pointer for sliding window
        int left = 0;
        
        // Count of valid substrings ending at the current right index
        int count = 0;
        
        // Total count of valid substrings
        long long substr = 0;

        // Helper function to remove the leftmost character from the window
        auto minus = [&] (char c) {
            if (vowels.count(c)) {
                // Decrement vowel frequency, and remove it from map if count reaches 0
                if (--vowelCount[c] == 0) {
                    vowelCount.erase(c);
                }
            } else {
                // Reduce the count of consonants in the window
                --cons;
            }
        };

        // Iterate through each character in the word (Right pointer of the sliding window)
        for (char c : word) {
            if (vowels.count(c)) {
                // If it's a vowel, increment its count in vowelCount map
                ++vowelCount[c];
            } else {
                // If it's a consonant, increase consonant count and reset valid substring count
                ++cons;
                count = 0;
            }

            // Shrink the window if consonant count exceeds k
            while (cons > k) {
                minus(word[left]); // Remove leftmost character
                ++left; // Move the left pointer to the right
            }

            // If window contains exactly k consonants and all 5 vowels, count valid substrings
            while (cons == k && vowelCount.size() == 5) {
                ++count;  // Found a valid substring
                minus(word[left]);  // Remove leftmost character to find more valid substrings
                ++left;  // Move left pointer further to explore more valid substrings
            }

            // Add count of valid substrings ending at this index
            substr += count;
        }

        return substr;
    }
};