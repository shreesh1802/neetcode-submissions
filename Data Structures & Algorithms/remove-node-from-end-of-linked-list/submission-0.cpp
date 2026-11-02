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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int t_n = 0;

        ListNode* temp = head;
        
        while(temp != nullptr)
        {
            temp = temp->next;
            t_n++;
        }
        
        temp = head;
        int d_n = t_n - n;
        int i = 0;

        if(d_n == 0)
        {
            return head->next;
        }

        while(temp!=nullptr)
        {
            if(i == d_n - 1)
            {
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
            i++;
        }
        return head;
    }
};
