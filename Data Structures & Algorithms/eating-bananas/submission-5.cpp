class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int res = right;

        while (left <= right) {
            int k = (left + right) / 2;
            long long time = 0;

            for (int i : piles) {
                time += ceil(static_cast<double>(i) / k);
            };

            if (time <= h) {
                res = k;
                right = k - 1;
            }
            else {
                left = k + 1;
            };
            
        };
        
        return res;
    };
};
