class Solution {
public:
    bool isValid(string s) {
        stack<char> opens;
        unordered_map<char, char> closedToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (closedToOpen.count(c)) {
                if (opens.empty()) {
                    return false;
                };
                
                if (opens.top() == closedToOpen[c]) {
                    opens.pop();
                    continue;
                };

                return false;
            }
            else {
                opens.push(c);
            };
        };

        return opens.empty();
    };
};
