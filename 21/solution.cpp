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
        if (l1==NULL && l2==NULL) return NULL;
        ListNode* result = new ListNode(INT_MIN), *now_node = result;
        while (l1 != NULL && l2!=NULL){
            if (l1->val <= l2->val){
                now_node->next = new ListNode(l1->val);
                now_node = now_node->next;
                l1 = l1->next;
            } else {
                now_node->next = new ListNode(l2->val);
                now_node = now_node->next;
                l2 = l2->next;
            }
        }
        if (l1==NULL && l2==NULL) return result->next;
        ListNode* continue_node = (l1==NULL ? l2 : l1);
        while(continue_node != NULL){
            now_node->next = new ListNode(continue_node->val);
            now_node = now_node->next;
            continue_node = continue_node->next;
        }
        return result->next;
    }
};