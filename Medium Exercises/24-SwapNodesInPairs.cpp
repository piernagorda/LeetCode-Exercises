//Author: Javier Piernagorda Olive
//Date: 5/1/2023

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* beginning = nullptr; //We make room for what we will return
        ListNode* current = head; //We start in the head
         //We will need to save the previous, to link after swapping
        if (head==nullptr || head->next == nullptr) return head;//One element or none
        else{ //2 or more elements in the list
            //We will grab pair by pair, swap them and make the new links
            
            ListNode* previous = nullptr;//We need the element prior to the current pair
            ListNode* nextElement = current->next; //We grab the next element (to make the code clearer)

            beginning = nextElement; //The head that we will return will be the 2nd element, this is, the next of the first current element. This is not touched anymore
            
            //While we can grab pairs
            while (current!= nullptr && nextElement!=nullptr){ 
                    ListNode* nextPair = nextElement->next; //We look 2 elements ahead, to link the 1st of the pair with the next pair (after the swap, the 1st will become the 2nd and will need to be linked with the next pair)
                    nextElement->next = current; //The next now points to the current
                    if (previous!=nullptr) previous->next = nextElement; //The previous points to the old 2nd element, now 1st 
                    current->next = nextPair; //We link the now moved element to the next pair
                    previous = current; //We update the previous to the 
                    current = nextPair; //Now, we move on to the next pair
                    
                    //We also need to grab the nextElement (to make coding easier), but we have to check we're not accesing a null pointer
                    if (current!= nullptr && current->next!=nullptr) nextElement = current->next;
                    else nextElement = nullptr;
            }
        }
        return beginning;
    }
};
