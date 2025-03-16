
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
int main()
{
    string s;
    cin >> s;
    map<char, int> c;
    set<char> sa;
    for (int i = 0; i < s.length(); i++)
    {
        c[s[i]]++;
        sa.insert(s[i]);
    }
    if (sa.size() != 2)
    {
        cout << "No" << endl;
        return 0;
    }
    for (auto i : sa)
    {
        if (c[i] != 2)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}



