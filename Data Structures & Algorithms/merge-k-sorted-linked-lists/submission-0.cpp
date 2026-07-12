/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    struct Compare{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode dummy;
        ListNode* tail = &dummy;
        for(ListNode* tmp : lists){
            while(tmp){
                pq.push(tmp);
                tmp=tmp->next;
            }
        }
        while(!pq.empty()){
            tail->next=pq.top();
            tail=tail->next;
            pq.pop();
        }
        tail->next=NULL;
        return dummy.next;
    }
};
