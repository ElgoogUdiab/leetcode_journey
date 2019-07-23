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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy = ListNode(0), *iter=&dummy, *next_iter=iter;
        dummy.next = head;
        while (1) {
            next_iter = iter;
            for(int i=0;i<k;++i){
                if (next_iter->next!=NULL) {
                    next_iter = next_iter->next;
                } else {
                    return dummy.next;
                }
            }
            ListNode* L = iter->next, *R = iter->next->next;
            for(int i=0;i<k-1;++i){
                L->next = R->next;
                R->next = iter->next;
                iter->next = R;
                R = L->next;
            }
            iter = L;
        }
        return dummy.next;
    }
};