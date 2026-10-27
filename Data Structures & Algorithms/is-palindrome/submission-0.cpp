#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        int p1 = 0;

        string s2;                                    

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')           
            {
                s2 += (char)(s[i] - 'A' + 'a');
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') ||
                     (s[i] >= '0' && s[i] <= '9'))    
            {
                s2 += s[i];
            }
           
        }

        int p2 = (int)s2.length() - 1;                

        while (p1 < p2)
        {
            if (s2[p1] != s2[p2]) return false;
            p1++;
            p2--;
        }
        return true;
    }
};