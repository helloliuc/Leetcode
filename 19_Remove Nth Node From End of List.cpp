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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front = head, *back;
        for(int i=1; i<=n && front != NULL ;i++) {
            front = front-> next;
        }
        if(front == NULL) {
            return head->next;
        }
        for(back = head; front ->next != NULL; front = front->next, back = back->next);
        back->next = back->next->next;
        return head;
    }
};
