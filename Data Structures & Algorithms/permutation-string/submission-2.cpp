class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int left = 0;
        int right = s1.size() - 1;
        sort(s1.begin(), s1.end());
        set<string> set1;
        set1.insert(s1);
        set<string> set2;

        while(right < s2.size()){
            string temp = s2.substr(left, right - left + 1);
            sort(temp.begin(), temp.end());
            set2.insert(temp);
            if(set1 == set2){
                return true;
            } else{
                set2.clear();
                left++;
                right++;
            }
        }
        return false;
    }
};
