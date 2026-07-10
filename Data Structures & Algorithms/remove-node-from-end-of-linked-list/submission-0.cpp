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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode* tmp=head;
        while(tmp){
            length++;
            tmp=tmp->next;
        }
        int i=length-n-1;
        tmp=head;
        if(i==-1) return head->next;
        while(i--) tmp=tmp->next;
        ListNode* next=tmp->next;
        tmp->next=tmp->next->next;
        delete next;
        return head;
    }
};
