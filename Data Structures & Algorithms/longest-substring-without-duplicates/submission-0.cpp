class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int longest = 0;

        for(int r = 0; r < s.size(); r++){
            // if the window is invalid (char is present in set)
            while(charSet.find(s[r]) != charSet.end()){
                charSet.erase(s[l]); // remove that character
                l++;
            }
            //if the window is valid and character is not present in set, add it
            charSet.insert(s[r]);
            int window = (r-l)+1;
            longest = max(longest, window);
        }
        return longest;
    }
};
