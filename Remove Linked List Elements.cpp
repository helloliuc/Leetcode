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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode *prev;
        while(head != NULL && head->val == val) {
            prev = head;
            head = head -> next;
            free(prev);
        }
        //Be CAREFUL!!!
        if(head == NULL)    return head;

        ListNode *cur = head->next;
        prev = head;
        while(cur != NULL) {
            if(cur->val == val) {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
