#include <unordered_map>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> mp;
        mp[nullptr] = nullptr;                  

        for (Node* c = head; c != nullptr; c = c->next)
        {
            mp[c] = new Node(c->val);
        }

        for (Node* c = head; c != nullptr; c = c->next)
        {
            mp[c]->next = mp[c->next];
            mp[c]->random = mp[c->random];
        }

        return mp[head];
    }
};