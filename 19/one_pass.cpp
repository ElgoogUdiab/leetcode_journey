
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
        ListNode *now_ptr, *prev_ptr=NULL;
        for (now_ptr = head; now_ptr!=NULL; now_ptr = now_ptr->next){
            ListNode *temp_ptr = now_ptr;
            for (int i=0;i<n;++i){
                temp_ptr = temp_ptr -> next;
            }
            if (temp_ptr == NULL){
                if (now_ptr == head) return head->next;
                prev_ptr->next = now_ptr->next;
                return head;
            }
            prev_ptr = now_ptr;
        }
        return NULL;
    }
};