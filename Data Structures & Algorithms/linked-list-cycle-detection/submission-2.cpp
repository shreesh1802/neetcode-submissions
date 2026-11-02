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
    bool hasCycle(ListNode* head) 
    {
        // if(head == nullptr)
        // {
        //     return false;
        // }
        // unordered_set<int> seen;

        // ListNode* temp = head;

        // while(temp->next != nullptr)
        // {
        //     if(seen.count(temp->val))
        //     {
        //         return true;
        //     }
        //     seen.insert(temp->val);
        //     temp = temp->next;
        // }   
        // return false; 

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
