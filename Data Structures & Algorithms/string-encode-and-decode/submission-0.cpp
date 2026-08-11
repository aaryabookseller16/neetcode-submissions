class Solution {
public:
    string encode(vector<string>& strs) {
    string result;

    for (const string& s : strs) {
        // Append the length of the string, followed by a delimiter (e.g. '#'), and then the string itself
        // This ensures we can reliably extract the string during decoding
        result += to_string(s.length()) + "#" + s;
    }

    return result;
}

    
    // Decodes a single string to a list of strings
vector<string> decode(string s) {
    vector<string> result;
    int i = 0;

    while (i < s.length()) {
        int j = i;

        // Find the position of the delimiter '#' to determine where the length ends
        while (s[j] != '#') {
            j++;
        }

        // Extract the length of the string from the substring before '#'
        int len = stoi(s.substr(i, j - i));

        // Extract the actual string of that length after the '#'
        result.push_back(s.substr(j + 1, len));

        // Move the index to the start of the next encoded string
        i = j + 1 + len;
    }

    return result;
}
};