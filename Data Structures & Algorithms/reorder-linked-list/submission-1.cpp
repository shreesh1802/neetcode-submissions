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
    void reorderList(ListNode* head) 
    {
        stack<ListNode*> stck;
        ListNode* temp = head;
        ListNode* curr = head;
        int n = 0;

        while(temp != nullptr)
        {
            stck.push(temp);
            temp = temp->next;
            n++;
        }
       

        for(int i = 0; i < n/2; i++)
        {
            ListNode* last = stck.top();
            stck.pop();

            ListNode* nxt = curr->next;
            curr->next = last;
            last->next = nxt;
            curr = nxt;
        }
        curr->next = nullptr;
    }
};
