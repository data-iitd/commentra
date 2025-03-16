
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int max_level;
    cin >> max_level;
    string s1, s2;
    cin >> s1 >> s2;
    set<int> x, y;
    for (int i = 0; i < s1.size(); i++)
    {
        x.insert(s1[i] - '0');
    }
    for (int i = 0; i < s2.size(); i++)
    {
        y.insert(s2[i] - '0');
    }
    x.erase(0);
    y.erase(0);
    set<int> z = x.union(y);
    if (z.size() != max_level)
    {
        cout << "Oh, my keyboard!" << endl;
    }
    else
    {
        cout << "I become the guy." << endl;
    }
    return 0;
}

