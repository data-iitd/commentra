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

    for (int i = 0; i < s.length(); i++)
    {
        if (i >= 1)
        {
            if (s[i] == ' ')
            {
                if (res[res.size() - 1] != ' ')
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
                if (s[i] in punctuation)
                {
                    if (res[res.size() - 1] == ' ')
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
            if (s[i] == ' ')
            {
                continue;
            }
            if (s[i] in punctuation)
            {
                continue;
            }
            else
            {
                res.push_back(s[i]);
            }
        }
    }

    string result = "";
    for (int i = 0; i < res.size(); i++)
    {
        result += res[i];
    }
    cout << result << endl;

    return 0;
}

