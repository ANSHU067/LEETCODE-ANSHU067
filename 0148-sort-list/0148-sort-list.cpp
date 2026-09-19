class Solution {
public:

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (left && right) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            } 
            else {
                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

        if (left)
            curr->next = left;
        else
            curr->next = right;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        // 0 or 1 node is already sorted
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split list
        ListNode* right = slow->next;
        slow->next = nullptr;

        // Sort both halves
        ListNode* left = sortList(head);
        right = sortList(right);

        // Merge
        return merge(left, right);
    }
};