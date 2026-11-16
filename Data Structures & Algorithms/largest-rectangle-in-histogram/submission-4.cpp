class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            
            while (!stk.empty() && (i == n || heights[stk.top()] > heights[i])) {
                int height = heights[stk.top()];
                stk.pop();
                int width = (stk.empty()) ? i : i - stk.top() - 1;
                maxArea = max(maxArea, height * width);
            };

            stk.push(i);
        };

        return maxArea;
    };
};
