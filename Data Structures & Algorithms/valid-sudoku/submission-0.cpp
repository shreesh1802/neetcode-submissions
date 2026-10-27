class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<int> rows[9];
        unordered_set<int> cols[9];
        unordered_set<int> boxes[9];

        for(int i = 0 ; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if(c == '.') continue;

                int b = (i/3)*3 + (j/3);  
                
                if(rows[i].count(c) || cols[j].count(c) || boxes[b].count(c))
                {
                    return false;
                }

                rows[i].insert(c);
                cols[j].insert(c);
                boxes[b].insert(c);
            }
        }
        return true;        
    }
};
