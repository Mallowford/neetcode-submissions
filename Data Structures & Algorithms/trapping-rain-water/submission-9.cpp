class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        vector<int> maxHeightLeft(height.size(), 0);
        vector<int> maxHeightRight(height.size(), 0);

        for (int i = 1; i < height.size(); i++) {
            maxHeightLeft[i] = max(height[i - 1], maxHeightLeft[i - 1]);
        };

        for (int i = height.size() - 2; i >= 0; i--) {
            maxHeightRight[i] = max(height[i + 1], maxHeightRight[i + 1]);
        };

        for (int i = 0; i < height.size(); i++) {
            int area = min(maxHeightRight[i], maxHeightLeft[i]) - height[i];
            if (area < 0) {
                continue;
            };
            res = res + area;
        };

        return res;
    };
};
