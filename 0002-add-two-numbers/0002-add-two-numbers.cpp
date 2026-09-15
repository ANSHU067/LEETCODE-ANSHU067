class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Dummy node to make creating the answer easier
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        int carry = 0;

        // Continue while there is a node in either list
        // or there is a carry left
        while (l1 != NULL || l2 != NULL || carry != 0) {
            
            int sum = carry;

            // Add digit from l1
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add digit from l2
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Store the current digit
            curr->next = new ListNode(sum % 10);

            // Calculate carry
            carry = sum / 10;

            // Move to next result node
            curr = curr->next;
        }

        return dummy->next;
    }
};