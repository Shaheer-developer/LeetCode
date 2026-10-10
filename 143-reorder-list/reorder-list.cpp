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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* current = slow->next;
        ListNode* prev = nullptr;
        ListNode* up = slow->next;
        slow->next = nullptr;
        while(current != nullptr){
            up = current->next;
            current->next = prev;
            prev = current;
            current = up;
        }
        
        ListNode* first = head;
        ListNode* first_memory = head;
        ListNode* second = prev;
        ListNode* second_memory = prev;
        while(second != nullptr && first != nullptr){
            first_memory = first->next;
            first->next = second;
            second_memory = second->next;
            second->next = first_memory;
            first = first_memory;
            second = second_memory;
        }
    }
};