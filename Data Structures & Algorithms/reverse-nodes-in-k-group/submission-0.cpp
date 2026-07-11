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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        ListNode* tail = &dummy;
        int tmp=k;
        ListNode* tempHead=head;
        ListNode* tempTail=head;
        while(tempTail){
            tmp--;
            if(tmp==0){
                ListNode* next = tempTail->next;
                tempTail->next=NULL;
                ListNode* rotatedHead = reverseLL(tempHead);
                tail->next=rotatedHead;
                tail=tempHead;
                tempHead=next;
                tempTail=next;
                tmp=k;
            } else tempTail=tempTail->next;
        }
        tail->next=tempHead;
        return dummy.next;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* pre = NULL;
        while(head){
            ListNode* next = head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};
