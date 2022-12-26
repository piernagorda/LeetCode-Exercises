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
        ListNode* current = head;
        ListNode* previous = nullptr;
        int counter = 0;
        //We need to get how many elements we have in the list first
        while (current!=nullptr){
            current = current->next;
            ++counter;
        }
        current = head;
        //Now, we can eliminate the nth element from the end
        if (counter-n==0) return head->next;
        else{
            for (int i=0; i<counter-n; ++i){
            previous = current;
            current = current->next;
            }
            //We've reached the n-th element
            if (current!=nullptr && previous!=nullptr) previous->next = current->next;
            return head;  
        }
    }
};