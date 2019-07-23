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
    // Slightly modified to speed up, no new operation is needed
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL && l2==NULL) return NULL;
        ListNode result_dummy = ListNode(0), *now_node = &result_dummy;
        while (l1 != NULL && l2!=NULL){
            if (l1->val <= l2->val){
                now_node->next = l1;
                l1 = l1->next;
            } else {
                now_node->next = l2;
                l2 = l2->next;
            }
            now_node = now_node->next;
            now_node->next = NULL;
        }
        ListNode* continue_node = (l1==NULL ? l2 : l1);
        now_node->next = continue_node;
        return result_dummy.next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Removing empty lists
        for (auto it = lists.begin(); it!=lists.end();){
            if (*it == NULL){
                it = lists.erase(it);
            } else {
                ++it;
            }
        }
        if (lists.size()==0) return NULL;
        
        list<ListNode*> result;
        for (auto ptr: lists){
            result.push_back(ptr);
        }
        // Merging. 
        while(result.size()>1) {
            ListNode *l1, *l2;
            l1 = *(--result.end());
            result.pop_back();
            l2 = *(--result.end());
            result.pop_back();
            result.push_front(mergeTwoLists(l1, l2);
        }
        return *result.begin();
    }
};