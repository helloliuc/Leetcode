/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)    return head;
        stack<ListNode*> s;
        ListNode *tmp = head;
        while(tmp != NULL) {
            s.push(tmp);
            tmp = tmp->next;
        }

        ListNode *newhead = s.top();
        ListNode *prev = s.top();   s.pop();
        while(!s.empty()) {
            tmp = s.top();  s.pop();
            prev -> next = tmp;
            tmp -> next = NULL;
            prev = tmp;
        }

        return newhead;
    }
};
