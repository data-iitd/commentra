#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int max = -1;
    int msgLength[s.length() / 2];
    int count = 0;
    int idx = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '.' || c == '?' || c == '!')
        {
            msgLength[idx++] = ++count;
            if (count > max)
                max = count;
            i++;
            count = 0;
        }
        else
            count++;
    }
    if (max > n)
        cout << "Impossible" << endl;
    else
    {
        int ans = 0;
        for (int i = 0; i < idx; i++)
        {
            int l = msgLength[i];
            while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n)
            {
                l += msgLength[i + 1] + 1;
                i++;
            }
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
