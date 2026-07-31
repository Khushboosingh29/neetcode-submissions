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
        
        ListNode* temp=head;
        ListNode* nextnode=NULL;
        ListNode*  prevnode=NULL;
        ListNode* k_node=NULL;
        while(temp!=NULL){
            k_node=findKnode(temp,k);
            if(k_node==NULL){
                if(prevnode)
                    prevnode->next=temp;
                 break;
            }
                nextnode=k_node->next;
                k_node->next=NULL;
                reverseList(temp);
                if(temp==head)
                    head=k_node;
                else{
                    prevnode->next=k_node;
                }
                prevnode=temp;
                temp=nextnode;
        }
        return head;
    }
  ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* newnode=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newnode;        
    }
 ListNode* findKnode(ListNode* temp,int k){
    k=k-1;
    while(temp!=NULL && k>0)
    {
        k--;
        temp=temp->next;

    }
    return temp;
 }
};