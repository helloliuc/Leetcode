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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode *newhead = head -> next;
        ListNode *prev = NULL;
        while(true) {
            if(head == NULL || head -> next == NULL) break;
            ListNode *tmp = head->next;
            head -> next = tmp -> next;
            tmp -> next = head;
            if(prev != NULL) prev->next = tmp;
            prev = head;
            head = head -> next;
        }
        
        return newhead;
    }
};
