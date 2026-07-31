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
    // Reverse a linked list and return the new head
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // If list is empty or k = 1, no change needed
        if (head == NULL || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;

        while (true) {
            // Find the kth node from prevGroupEnd
            ListNode* kth = prevGroupEnd;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                // Less than k nodes remaining
                if (kth == NULL) return dummy.next;
            }

            // Save important pointers
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroup = kth->next;

            // Break the current group
            kth->next = NULL;

            // Reverse current group
            ListNode* newHead = reverse(groupStart);

            // Connect previous part with reversed group
            prevGroupEnd->next = newHead;

            // Connect reversed group's tail to next group
            groupStart->next = nextGroup;

            // Move prevGroupEnd to the tail of reversed group
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};