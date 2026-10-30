class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> stck;
        for(int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stck.push(s[i]);                       
            }
            else
            {
                if(stck.empty())
                {
                    return false;
                }
                if(stck.top() == '{' && s[i] == '}')
                {
                    stck.pop();
                }
                else if(stck.top() == '[' && s[i] == ']')
                {
                    stck.pop();
                }
                else if(stck.top() == '(' && s[i] == ')')
                {
                    stck.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return stck.empty();
    }
};
