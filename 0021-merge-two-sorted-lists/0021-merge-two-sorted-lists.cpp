class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Dummy node to simplify handling of the head
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        // Compare nodes from both lists
        while (list1 != NULL && list2 != NULL) {
            
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } 
            else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        // Attach remaining nodes
        if (list1 != NULL)
            curr->next = list1;
        else
            curr->next = list2;

        return dummy->next;
    }
};