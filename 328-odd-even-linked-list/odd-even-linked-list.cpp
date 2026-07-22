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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        vector<int> arr;

        // Step 1: Collect odd indexed values
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) arr.push_back(temp->val);

        // Step 2: Collect even indexed values
        temp = head->next;
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) arr.push_back(temp->val);

        // Step 3: Reconstruct by replacing node values
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};
