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
    int getLen(ListNode* head){
        int maxi = 0;
        while(head != nullptr){
            maxi++;
            head = head -> next;
        }
        return maxi;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       int lena = getLen(headA);
       int lenb = getLen(headB);
       int target = 0; 
    if(lena> lenb ){
        target = lena - lenb;
        for(int i =0; i<target; i++){
            headA = headA-> next;
        }
        while(headA && headB) {
    if(headA == headB)
        return headA;
    headA = headA->next;
    headB = headB->next;
}
    }
    else{
        target = lenb - lena;
        for(int i =0; i<target; i++){
            headB = headB-> next;
        }
        while(headA && headB) {
    if(headA == headB)
        return headA;
    headA = headA->next;
    headB = headB->next;
}
    }
            

     return nullptr ;
    }
};