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
        ListNode* temp = head;
        ListNode* temp2 = head;
        ListNode* prev = head;
        ListNode* result;
        if(head == nullptr || head->next == nullptr) result = head;
        else result = head->next;
        while(temp != nullptr && temp2 != nullptr && temp->next != nullptr &&temp2->next != nullptr){
            temp2 = temp->next->next;
            temp->next->next = temp;
            if(temp != head) prev->next = temp->next;
            prev = temp;
            temp->next = temp2;
            temp = temp2;  
        }
        return result;
    }
};