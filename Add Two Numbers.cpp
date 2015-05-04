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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        ListNode *ret = new ListNode(0);
        ListNode *cur = ret;
        while(l1 || l2 || add) {
            cur->next = new ListNode((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + add);
            add = cur->next->val / 10;
            cur->next->val %= 10;
            cur = cur->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        cur = ret -> next;
        delete ret;
        return cur;
    }
};
