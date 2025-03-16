#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<vector<string>> t;
    for (int i = 0; i < 4; i++)
    {
        vector<string> l;
        for (int j = 0; j < 3; j++)
        {
            string s;
            cin >> s;
            l.push_back(s);
        }
        t.push_back(l);
    }
    int black = 0;
    int white = 0;
    int correct = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (t[i][j] == "#")
            {
                black++;
            }
            else
            {
                white++;
            }
            if (t[i][j + 1] == "#")
            {
                black++;
            }
            else
            {
                white++;
            }
            if (t[i + 1][j] == "#")
            {
                black++;
            }
            else
            {
                white++;
            }
            if (t[i + 1][j + 1] == "#")
            {
                black++;
            }
            else
            {
                white++;
            }
            if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4)
            {
                correct = 1;
                break;
            }
            black = 0;
            white = 0;
        }
    }
    if (correct == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}