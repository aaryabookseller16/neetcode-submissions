class Solution {
public:
    bool isPalindrome(string s) {
        bool ans = true;
        int i = 0;
        string temp = s;

        for (char &c : temp) {
            c = std::tolower(c);
        }
        std::string charsToRemove = " .?!=[]{}-_/()*&^%$#@!',:";
        temp.erase(std::remove_if(temp.begin(), temp.end(),  [&charsToRemove](char c) {return charsToRemove.find(c) != std::string::npos;}), temp.end());
        int j = temp.size()-1;

        while(i < j){
            if(temp[i] != temp[j]){
                cout << "temp i = " << temp[i] << "    temp j = " << temp[j] << endl;
                return false;
            }
            i++;
            j--;
        }
        return ans;
    }
};
