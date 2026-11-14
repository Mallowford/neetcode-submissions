class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {

            while (!stk.empty() && (i == n || heights[stk.top()] >= heights[i])) {
                int h = heights[stk.top()];
                stk.pop();
                int w = (stk.empty()) ? i : ((i - stk.top()) - 1);

                maxArea = max(maxArea, h * w);
            };

            stk.push(i);
        };

        return maxArea;
    };
};
