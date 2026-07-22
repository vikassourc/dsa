class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode* temp =head;

        // Push all values into stack
        while (temp!=NULL) {
            st.push(temp->val);
            temp=temp->next;
        }

        // Traverse again and compare with stack top
        temp=head;
        while (temp != NULL) {
            if (temp->val!=st.top()) {
                return false;
            }
            st.pop();
            temp=temp->next;
        }

        return true;
    }
};
