#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    while (n--)
    {
        int num;
        cin >> num;
        if (m.lower_bound(num) == m.end())
        {
            int val = m[num];
            m[num] = val + 1;
        }
        else
        {
            int key = m.lower_bound(num)->first;
            int val = m[key];
            if (val == 1)
                m.erase(key);
            else
                m[key] = val - 1;
            val = m[num];
            m[num] = val + 1;
        }
    }
    int ans = 0;
    for (auto it = m.begin(); it!= m.end(); it++)
        ans += it->second;
    cout << ans << endl;
    return 0;
}
