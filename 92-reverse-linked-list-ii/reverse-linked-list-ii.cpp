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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* first = nullptr;
        ListNode* last = head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* start = nullptr;
        for(int i = 1; i < left; i++){
            prev = temp;
            temp = temp->next;
        }
        start = temp;
        for(int j = 0; j < right; j++){
            last = last->next;
        }
        first = prev;
        prev = nullptr;
        int i = right-left + 1;
        while(i > 0){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            i--;
        }
        if(first != nullptr){
        first->next = prev;
        }
        start->next = last;
        if(first == nullptr){
            return prev;
        }
        return head;
    }
};