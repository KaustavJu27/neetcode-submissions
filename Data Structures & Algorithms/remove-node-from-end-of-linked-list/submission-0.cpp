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
    // Function to calculate the size of the linked list
    int size(ListNode* temp) {
        int count = 0;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = size(head);  // Find total length of list

        // Case 1: Only one node
        if (length == 1) {
            delete head;
            return NULL;
        }

        // Case 2: Delete the first node
        else if (length == n) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Case 3: Delete any middle/last node
        else {
            ListNode* prev = NULL;  // Previous node
            ListNode* temp = head;  // Current node

            int steps = length - n;  // Move to the node that has to be deleted

            while (steps--) {
                prev = temp;
                temp = temp->next;
            }

            // Skip the node to be deleted
            prev->next = temp->next;

            // Free memory
            delete temp;

            return head;
        }
    }
};