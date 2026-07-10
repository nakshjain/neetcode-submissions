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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode dummy;
        ListNode* tail=&dummy;
        while(l1 && l2){
            int val = l1->val + l2->val + carry;
            carry=val/10;
            ListNode* newNode = new ListNode(val%10);
            tail->next=newNode;
            tail=tail->next;
            l1=l1->next;
            l2=l2->next;
        }
        ListNode* remaining = l1 ? l1 : l2;
        while(remaining){
            int val = remaining->val + carry;
            carry=val/10;
            ListNode* newNode = new ListNode(val%10);
            tail->next=newNode;
            tail=tail->next;
            remaining=remaining->next;
        }
        if(carry!=0) {
            ListNode* newNode = new ListNode(carry);
            tail->next=newNode;
        }
        return dummy.next;
    }
};
