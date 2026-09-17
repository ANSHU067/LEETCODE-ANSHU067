class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {

            // Check if current value is duplicated
            if (curr->next != NULL && curr->val == curr->next->val) {

                // Skip all nodes having the same value
                while (curr->next != NULL &&
                       curr->val == curr->next->val) {
                    curr = curr->next;
                }

                // Remove the entire duplicate group
                prev->next = curr->next;
            }
            else {
                // Current node is unique
                prev = prev->next;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};