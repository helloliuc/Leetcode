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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(0);
        ListNode *head = ret;
        while(l1 && l2) {
            if(l1 -> val < l2 -> val) {
                ret -> next = new ListNode(l1 -> val);
                l1 = l1 -> next;
                ret = ret -> next;
            }
            else {
                ret ->next = new ListNode(l2 -> val);
                l2 = l2 -> next;
                ret = ret -> next;
            }
        }
        while(l1) {
            ret -> next = new ListNode(l1 -> val);
            ret = ret -> next;
            l1 = l1 -> next;
        }
        while(l2) {
            ret -> next = new ListNode(l2 -> val);
            ret = ret -> next;
            l2 = l2 -> next;
        }
        ret = head -> next;
        delete head;
        return ret;
    }
};
