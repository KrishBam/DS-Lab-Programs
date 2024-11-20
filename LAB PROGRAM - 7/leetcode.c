/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    int count=0;
    struct ListNode* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    int mid;
    if(count%2==0){
        mid=(count/2)+1;
    }
    else{
        mid=(count+1)/2;
    }
    temp=head;
    count=1;
    while(count!=mid){
        temp=temp->next;
        count++;
    }
    return temp;
}
