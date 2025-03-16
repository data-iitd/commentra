#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int k;
    cin >> k;
    int l = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]!= '1')
            break;
        l++;
    }
    if (l >= k)
        return 1;
    return s[l];
}
