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
    void reorderList(ListNode* head) {
        int n=0;
        ListNode* tmp=head;
        while(tmp){
            n++;
            tmp=tmp->next;
        }
        n=(n+1)/2-1;
        tmp=head;
        while(n--){
            tmp=tmp->next;
        }
        ListNode* tmp2=tmp->next;
        tmp->next=NULL;
        tmp=tmp2;
        stack<ListNode*> st;
        while(tmp){
            st.push(tmp);
            tmp=tmp->next;
        }
        tmp=head;
        while(!st.empty()){
            ListNode* tmp2=tmp->next;
            tmp->next=st.top();
            st.pop();
            tmp->next->next=tmp2;
            tmp=tmp2;
        }
    }
};
