class Solution {
public:
    ListNode* RecurseNodes(ListNode* temp, int k, int n_g)
    {
        if (n_g == 0) return temp;           

        ListNode* prev = nullptr;
        ListNode* curr = temp;
        ListNode* start = temp;             

        for (int n = 0; n < k; n++)          
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        

        start->next = RecurseNodes(curr, k, n_g - 1);  
        return prev;                                    
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int n_t = 0;
        ListNode* itr = head;

        while (itr != nullptr)
        {
            itr = itr->next;
            n_t++;
        }
        int n_g = n_t / k;

        return RecurseNodes(head, k, n_g);
    }
};