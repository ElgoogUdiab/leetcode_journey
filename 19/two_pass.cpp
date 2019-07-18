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
        ListNode *now_ptr;
        int length=0;
        for (now_ptr = head; now_ptr!=NULL; now_ptr = now_ptr->next) ++length;
        if (length == n) return head->next;
        
        now_ptr = head;
        for (int i=0; i<length-n-1;++i) now_ptr = now_ptr->next;
        now_ptr->next = now_ptr->next->next;
        return head;
    }
};