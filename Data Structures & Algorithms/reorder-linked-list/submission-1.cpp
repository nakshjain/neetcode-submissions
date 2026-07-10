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
        ListNode* reversedLL=tmp->next;
        tmp->next=NULL;
        tmp=head;
        reversedLL=reverseLL(reversedLL);

        while(reversedLL){
            ListNode* next1=tmp->next;
            ListNode* next2=reversedLL->next;
            tmp->next=reversedLL;
            reversedLL->next=next1;
            tmp=next1;
            reversedLL=next2;
        }
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* pre=NULL;
        while(head){
            ListNode* next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};
