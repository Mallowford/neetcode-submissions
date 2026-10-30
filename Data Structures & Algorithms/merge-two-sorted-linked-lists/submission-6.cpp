/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    private:
        ListNode* nextVal(ListNode* curr_1, ListNode* curr_2) {
            if (curr_1 == nullptr || curr_2 == nullptr) {
                ListNode* ret = ((curr_1 == nullptr) ? curr_2 : curr_1);
                return ret;                
            };
            return ((curr_1->val < curr_2->val) ? curr_1 : curr_2);
        };
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* head = nullptr;
            ListNode* prev = nullptr;
            ListNode* curr = nullptr;
            ListNode* curr_1 = list1;
            ListNode* curr_2 = list2;

            do {
                curr = nextVal(curr_1, curr_2);

                if (prev != nullptr) {
                    prev->next = curr;
                };

                prev = curr;
                
                if (curr != nullptr) {
                    if (prev == curr_1) {
                        curr_1 = curr_1->next;
                    }
                    else {
                        curr_2 = curr_2->next;
                    };
                };

                if (head == nullptr) {
                    head = prev;
                };
            } while (curr != nullptr);


            return head;
        };
};
