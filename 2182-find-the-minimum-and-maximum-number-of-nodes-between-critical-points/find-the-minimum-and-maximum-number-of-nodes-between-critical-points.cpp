class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> ans = {-1, -1};
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int index = 1;
        int first = -1;
        int last = -1;
        int mini = INT_MAX;
        
        while (curr->next != NULL) {
            
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (first == -1) {
                    first = index;
                }
                else {
                    mini = min(mini, index - last);
                }
                
                last = index;
            }
            
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        if (first == last)
            return ans;
        
        ans[0] = mini;
        ans[1] = last - first;
        
        return ans;
    }
};