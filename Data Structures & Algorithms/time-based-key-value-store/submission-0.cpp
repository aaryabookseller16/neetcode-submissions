class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end()) return "";

        auto& values = m[key]; // find the key where we are looking for the timestamp
        int left = 0, right = values.size()-1;
        string result = "";

        // do a binary search in that key based on the timestamp
        while(left <= right){
            int mid = (left + right)/2;

           // if element is found or is less than the timestamp
            if(values[mid].first <= timestamp) {// if element is less than mid point
                left = mid + 1;
                result = values[mid].second;
            }
            else { // if element is greater than timestamp
                right = mid - 1;
            } 
        }
        return result;
    }
};
