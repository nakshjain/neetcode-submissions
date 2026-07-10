/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* newHead=NULL;
        Node* tail=NULL;
        Node* tail2=head;
        while(tail2){
            if(newHead==NULL){
                newHead=new Node(head->val);
                tail=newHead;
            } else {
                Node* newNode = new Node(tail2->val);
                tail->next=newNode;
                tail=tail->next;
            }
            map[tail2]=tail;
            tail2=tail2->next;
        }
        tail2=head;
        tail=newHead;
        while(tail2){
            if(!tail2->random) tail->random=NULL;
            else tail->random=map[tail2->random];
            tail=tail->next;
            tail2=tail2->next;
        }
        return newHead;
    }
};
