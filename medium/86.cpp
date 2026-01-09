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
    ListNode* partition(ListNode* head, int x) {
        ListNode *first = nullptr, *second = nullptr, *firstTail = nullptr, *secondTail = nullptr;
        
        while(head != nullptr){
            ListNode* n = new ListNode(head->val);
            if(head->val < x){
                if(first == nullptr) first = n;
                else firstTail->next = n;
                firstTail = n;
            } else {
                if(second == nullptr) second = n;
                else secondTail->next = n;
                secondTail = n;
            }
            head = head->next;
        } 

        if(firstTail != nullptr) firstTail->next = second;
        else return second;
        return first;      
    }
};