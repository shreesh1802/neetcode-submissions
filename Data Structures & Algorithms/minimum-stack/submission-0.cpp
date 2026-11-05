class MinStack {
public:
    stack<int> stck;
    stack<int> minstck;
    MinStack() 
    {  
    }
    
    void push(int val) 
    {
        stck.push(val);
        if(minstck.empty())
        {
            minstck.push(val);
        }
        else
        {
            minstck.push(min(val,minstck.top()));
        }   
    }
    
    void pop() 
    {
        stck.pop();
        minstck.pop();    
    }
    
    int top() 
    {
        return stck.top();    
    }
    
    int getMin() 
    {
        return minstck.top();    
    }
};
