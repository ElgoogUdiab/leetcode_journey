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
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode *iter_ptr, *temp;
        for (iter_ptr=&dummy; iter_ptr->next!=NULL && iter_ptr->next->next!=NULL;iter_ptr=iter_ptr->next->next) {
            temp = iter_ptr->next->next;
            iter_ptr->next->next = temp->next;
            temp->next = iter_ptr->next;
            iter_ptr->next = temp;
        }
        return dummy.next;
    }
};