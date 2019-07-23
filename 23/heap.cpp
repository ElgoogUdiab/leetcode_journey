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
    // Compare function for ListNode
    static inline bool comp_func(ListNode* a, ListNode* b) {
        return a->val >= b->val;
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
        
        ListNode result_dummy = ListNode(0);
        ListNode *result = &result_dummy;
        make_heap(lists.begin(), lists.end(), comp_func);
        
        while(lists.size()){
            ListNode* item = lists.front();
            pop_heap(lists.begin(), lists.end(), comp_func); lists.pop_back();
            result->next = item;
            if (item->next != NULL){
                lists.push_back(item->next); push_heap(lists.begin(), lists.end(), comp_func);
                item->next = NULL;
            }
            result = result->next;
        }
        
        return result_dummy.next;
    }
};