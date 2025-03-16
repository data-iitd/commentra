
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<int> menu;
    for (int i = 0; i < 5; i++)
    {
        string m;
        cin >> m;
        int e = m[m.length() - 1] - '0';
        if (e == 0)
            e = 10;
        menu.push_back(stoi(m) * 10 + e);
    }
    sort(menu.begin(), menu.end());
    int ans = 0;
    for (int i = 1; i < menu.size(); i++)
    {
        ans += ceil(menu[i] / 10.0) * 10;
    }
    cout << ans + menu[0] / 10;
    return 0;
}
