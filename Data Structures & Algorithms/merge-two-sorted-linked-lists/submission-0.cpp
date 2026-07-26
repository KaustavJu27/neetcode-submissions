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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }

        if ((list1 == NULL && list2 != NULL)) {
            return list2;
        } else if (list1 != NULL && list2 == NULL) {
            return list1;
        }

        while (list1 != NULL && list2 != NULL) {
            if (list1->val == list2->val || list1->val < list2->val) {
                tail->next = list1;   // Attach list1 node
                list1 = list1->next;  // Move list1
            } else {
                tail->next = list2;   // Attach list2 node
                list2 = list2->next;  // Move list2
            }

            tail = tail->next;  // move tail
        }
        // Attach the remaining nodes
        if (list1 != NULL)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
    }
};
