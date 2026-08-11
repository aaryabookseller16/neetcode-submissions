class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap; // element -> frequency

        for (int num : nums) {
            umap[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n + 1); // freq from 1 to n

        for (auto& pair : umap) {
            int num = pair.first;
            int freq = pair.second;
            buckets[freq].push_back(num);
        }

        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
