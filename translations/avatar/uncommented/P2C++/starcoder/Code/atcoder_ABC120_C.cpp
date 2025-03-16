#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i + 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
