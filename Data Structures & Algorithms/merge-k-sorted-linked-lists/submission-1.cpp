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
    // Merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy;           // Dummy node to simplify merging
        ListNode* tail = &dummy;  // Points to the last node of merged list

        // If both lists are empty
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }

        // If one list is empty, return the other list
        if (list1 == NULL && list2 != NULL) {
            return list2;
        } else if (list1 != NULL && list2 == NULL) {
            return list1;
        }

        // Compare nodes from both lists and attach the smaller one
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // Attach the remaining nodes of the non-empty list
        if (list1 != NULL)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;  // Stores the merged result

        // Merge each list one by one with the current answer
        for (int i = 0; i < lists.size(); i++) {
            ans = merge(ans, lists[i]);
        }

        return ans;
    }
};