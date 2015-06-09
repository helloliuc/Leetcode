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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 =  0, l2 = 0;
        for(ListNode *tmp = headA; tmp != NULL; tmp = tmp -> next) {
            l1 ++;
        }
        for(ListNode* tmp = headB; tmp != NULL; tmp = tmp -> next) {
            l2 ++;
        }
        int diff = max(l1, l2) - min(l1, l2);
        if(l1 < l2) {
            swap(headA, headB);
        }
        while(diff > 0) {
            headA = headA -> next;
            diff--;
        }
        while(headA != headB) {
            headA = headA->next;    headB = headB->next;
        }
        return headA;
    }
};
