#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int game(vector<int>& guess,vector<int>&answer)
    {
        int ret = 0;
        for(int i = 0; i < 3;++i)
        {
            if(guess[i] == answer[i])
            {
                ret++;
            }
        }
        return ret;
    }
};

//本地测试用:每组先读3个guess,再读3个answer,输出猜对的次数
int main()
{
    Solution s;
    vector<int> guess(3),answer(3);
    while(cin >> guess[0] >> guess[1] >> guess[2]
              >> answer[0] >> answer[1] >> answer[2])
    {
        cout << s.game(guess,answer) << endl;
    }
    return 0;
}
