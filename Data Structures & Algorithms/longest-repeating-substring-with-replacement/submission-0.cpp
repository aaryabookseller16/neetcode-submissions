class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty()) return 0;

        unordered_map<char,int> freq; // stores frequency of each character in current window
        int left = 0;                  // left pointer of sliding window
        int maxFreq = 0;               // max frequency of a single character in current window
        int best = 0;                  // length of longest valid window found so far

        for (int right = 0; right < (int)s.size(); ++right) {
            // Add current character to the frequency map and update maxFreq
            maxFreq = max(maxFreq, ++freq[s[right]]);

            // If we need more than k replacements to make all chars equal, shrink window from left
            // (window length - most frequent char count > k means it's invalid)
            while ((right - left + 1) - maxFreq > k) {
                if (--freq[s[left]] == 0) 
                    freq.erase(s[left]); // optional: keeps map clean
                ++left; // move left boundary forward
            }

            // Update the best length found so far
            best = max(best, right - left + 1);
        }
        return best;
    }
};
