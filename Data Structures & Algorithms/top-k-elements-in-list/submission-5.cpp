class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]] = freq[nums[i]] + 1;
        };
        vector<vector<int>> counts(nums.size() + 1);
        for (auto i : freq) {
            counts[i.second].push_back(i.first);
        };
        vector<int> res;
        for (int i = counts.size() - 1; i > 0; i--) {
            for (int n : counts[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                };
            };
        };


        return res;
    };
};
