
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // Step 1: Reverse the linked list
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;

        // Step 2: Find next greater elements
        vector<int> ans;
        stack<int> st;

        while (head != nullptr) {
            int val = head->val;

            while (!st.empty() && st.top() <= val) {
                st.pop();
            }

            if (st.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(st.top());
            }

            st.push(val);
            head = head->next;
        }

        // Step 3: Reverse the answer
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
