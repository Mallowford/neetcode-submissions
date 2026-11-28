/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private:
    public:
        Node* copyRandomList(Node* head) {
            unordered_map<Node*, Node*> copy;
            copy[nullptr] = nullptr;

            Node* curr = head;
            while (curr) {
                if (copy.find(curr) == copy.end()) { // Means new node
                    copy[curr] = new Node(0);
                };
                copy[curr]->val = curr->val;
                if (copy.find(curr->next) == copy.end()) {
                    copy[curr->next] = new Node(0);
                };
                copy[curr]->next = copy[curr->next];
                if (copy.find(curr->random) == copy.end()) {
                    copy[curr->random] = new Node(0);
                };
                copy[curr]->random = copy[curr->random];

                curr = curr->next;
            };

            return copy[head];
        };
};
