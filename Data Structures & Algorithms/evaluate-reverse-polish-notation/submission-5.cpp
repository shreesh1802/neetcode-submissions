class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> stck;
        for(int i = 0; i < tokens.size(); i++)
        {
            int a;
            int b;
            if(tokens[i].back() >= '0' && tokens[i].back() <= '9')
                stck.push(stoi(tokens[i])),cout<<stck.top()<<endl;
            
            else {
                a = stck.top(); stck.pop();
                b = stck.top(); stck.pop();
                if(tokens[i][0] == '+')
                {
                    stck.push(a+b);  
                }
                else if(tokens[i][0] == '-')
                {
                    stck.push(b-a); 
                }
                else if(tokens[i][0] == '*')
                {
                    stck.push(a*b);
                }
                else
                { 
                    stck.push(b/a); 
                }
            }
        }
        return stck.top();
    }
};
