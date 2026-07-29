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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);  // Dummy node to simplify list creation
        ListNode* tail = dummy;             // Points to the last node of answer list

        int carry = 0;

        // Continue while either list has nodes or carry remains
        while (l1 != NULL || l2 != NULL || carry) {
            int sum = carry;

            // Add value from first list
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from second list
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;      // Calculate carry
            int digit = sum % 10;  // Digit to store

            tail->next = new ListNode(digit);  // Create new node
            tail = tail->next;                 // Move tail forward
        }

        ListNode* ans = dummy->next;
        delete dummy;  // Free dummy node

        return ans;
    }
};
