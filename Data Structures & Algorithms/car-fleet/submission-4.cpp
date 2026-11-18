class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> stk;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            stk.push_back({position[i], speed[i]});
        };

        sort(stk.rbegin(), stk.rend());

        int fleets = 1;
        double prevTime = (double)(target - stk[0].first) / stk[0].second;

        for (int i = 1; i < n; i++) {
            double currTime = (double)(target - stk[i].first) / stk[i].second;
            
            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            };
        };

        return fleets;
    };
};
