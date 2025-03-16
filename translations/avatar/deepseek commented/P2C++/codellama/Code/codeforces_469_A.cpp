#include <iostream>
#include <set>
using namespace std;

int main()
{
    int max_level;
    cin >> max_level;
    int x[max_level], y[max_level];
    for (int i = 0; i < max_level; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < max_level; i++)
    {
        cin >> y[i];
    }
    set<int> s1, s2;
    for (int i = 0; i < max_level; i++)
    {
        s1.insert(x[i]);
        s2.insert(y[i]);
    }
    s1.erase(0);
    s2.erase(0);
    if (s1.size() != max_level && s2.size() != max_level)
    {
        cout << "Oh, my keyboard!";
    }
    else
    {
        cout << "I become the guy.";
    }
    return 0;
}
