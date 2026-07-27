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
   public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited;

        ListNode* temp = head;

        while (temp != NULL) {
            // If we've already seen this node, there's a cycle
            if (visited.find(temp) != visited.end()) {
                return true;
            }

            // Mark this node as visited
            visited.insert(temp);

            temp = temp->next;
        }

        return false;
    }
};
