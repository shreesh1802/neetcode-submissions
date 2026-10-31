class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
    
        vector<int> res;
        vector<int> f_idx;
        int p_idx = 0;
        vector<double> time;
        int fleet = 0;

        for(int i = 0; i < position.size(); i++)
        {
            res.push_back(position[i]);
        }

        sort(res.begin(),res.end(), greater<int>());

        unordered_map<int,int> where;              
        for(int i = 0; i < position.size(); i++)
        {
            where[position[i]] = i;
        }

        for(int k = 0; k < res.size(); k++)
        {
            f_idx.push_back(where[res[k]]);        
        }
        
        for(int i = 0; i < f_idx.size(); i++)
        {
            time.push_back((double)(target - position[f_idx[i]]) / speed[f_idx[i]]);
        }
      
        int p1 = 0; int p2 = 1;
        fleet = 1;
        while(p2 < time.size())
        {
            if(time[p1] < time[p2])
            {
                fleet++;
                p1 = p2;
            }
            p2++;
        }
        return fleet;
    }
};
