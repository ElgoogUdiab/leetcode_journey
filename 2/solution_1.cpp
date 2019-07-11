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
        int carry = 0;
        auto *list_return = new ListNode(NULL);
        auto *list_iter = list_return;
        while (1){
            int x = l1->val + l2->val + carry;
            carry = x>=10;
            x%=10;
            list_iter->val = x;
            l1 = l1->next;l2=l2->next;
            if ( l1 == NULL || l2 == NULL) break;
            list_iter->next = new ListNode(NULL);
            list_iter = list_iter->next;
        }
        if (l1 != NULL){
            while (l1!=NULL){
                int x = l1->val + carry;
                carry = x>=10;
                list_iter->next = new ListNode(x%=10);
                list_iter = list_iter->next;
                l1 = l1->next;
            }
        } else if (l2 != NULL){
            while (l2!=NULL){
                int x = l2->val + carry;
                carry = x>=10;
                list_iter->next = new ListNode(x%=10);
                list_iter = list_iter->next;
                l2 = l2->next;
            }
        }
        if (carry){
            list_iter->next = new ListNode(NULL);
            list_iter = list_iter->next;
            list_iter->val = 1;
        }
        return list_return;
    }
};