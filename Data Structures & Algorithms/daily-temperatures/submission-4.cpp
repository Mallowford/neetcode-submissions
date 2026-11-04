class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stk.empty() && t > stk.top().first) {
                pair<int, int> popped = stk.top();
                stk.pop();
                res[popped.second] = i - popped.second;
            };
            stk.push({t, i});
        };

        return res;
    };
};
