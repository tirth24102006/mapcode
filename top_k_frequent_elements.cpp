class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for (int num : nums) {
            freqMap[num]++;
        }
        for (auto& pair : freqMap) {
            int freq = pair.second;
            bucket[freq].push_back(pair.first);
        }
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; --i) {
            if (!bucket[i].empty()) {
                for (int num : bucket[i]) {
                    result.push_back(num);
                    if (result.size() == k) break; 
                }
            }
        }
        return result;
    }
};
