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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while(p1 != nullptr || p2 != nullptr || carry != 0)
        {
            int sum = carry;
            if(p1 != nullptr)
            {
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2 != nullptr)
            {
                sum += p2->val;
                p2 = p2->next;
            }

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            carry = sum / 10;
        }
        return dummy.next;
    }
};
