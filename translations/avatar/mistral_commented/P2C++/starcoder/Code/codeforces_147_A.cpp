#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<char> res;

    vector<char> punctuation = {',', '.', '!', '?'};

    for (int i = 0; i < s.size(); i++)
    {
        if (i >= 1)
        {
            if (s[i] =='')
            {
                if (res.back()!='')
                {
                    res.push_back(' ');
                }
                else
                {
                    continue;
                }
            }
        }
        else if (s[i] =='' && res.back() =='')
        {
            res.pop_back();
            res.push_back(s[i]);
            res.push_back(' ');
        }
        else if (s[i] =='' && res.back()!='')
        {
            res.push_back(s[i]);
        }
        else if (s[i] =='' && res.back() =='')
        {
            res.push_back(s[i]);
        }
        else if (s[i] in punctuation)
        {
            if (res.back() =='')
            {
                res.pop_back();
                res.push_back(s[i]);
                res.push_back(' ');
            }
            else
            {
                res.push_back(s[i]);
            }
        }
        else
        {
            res.push_back(s[i]);
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }

    return 0;
}

