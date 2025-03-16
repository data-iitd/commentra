#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<string> res;
    string punctuation = ",.!?";
    for (int i = 0; i < s.length(); i++)
    {
        if (i >= 1)
        {
            if (s[i] =='')
            {
                if (res.back()!='')
                {
                    res.push_back(s[i]);
                }
                else
                {
                    continue;
                }
            }
            else
            {
                if (s[i] == punctuation[0] || s[i] == punctuation[1] || s[i] == punctuation[2] || s[i] == punctuation[3])
                {
                    if (res.back() =='')
                    {
                        res.pop_back();
                    }
                    res.push_back(s[i]);
                    res.push_back(' ');
                }
                else
                {
                    res.push_back(s[i]);
                }
            }
        }
        else
        {
            if (s[i] =='')
            {
                continue;
            }
            if (s[i] == punctuation[0] || s[i] == punctuation[1] || s[i] == punctuation[2] || s[i] == punctuation[3])
            {
                continue;
            }
            else
            {
                res.push_back(s[i]);
            }
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    return 0;
}
