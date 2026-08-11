class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        // Populate the map with sorted string as key and original strings as values
        for (const auto& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(str);
        }

        // Extract the grouped anagrams from the map
        vector<vector<string>> result;
        for (auto& entry : anagramMap) {
            result.push_back(std::move(entry.second));
        }

        return result;
    }
};
