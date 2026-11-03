class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert({nums[i]});
        };

        int max = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i] - 1) != st.end()) {
                continue;
            };
            int potential = 1;
            int nextnum = nums[i] + 1;
            while (st.find(nextnum++) != st.end()) {
                potential++;
            };
            max = std::max(potential, max);
        };

        return max;
    };
};
