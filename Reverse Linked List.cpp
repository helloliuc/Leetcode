/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Take Care Of head == NULL
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)    return head;
        if(head ->next == NULL) {
            return head;
        }
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};
