class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);

        int slow2 = 0;
        do {
            slow2 = nums[slow2];
            slow = nums[slow];
        } while (slow != slow2);

        return slow;
    };
};
