
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (m.find(a[i]) == m.end())
        {
            m[a[i]] = 1;
        }
        else
        {
            m[a[i]]++;
        }
    }
    int max = 0;
    for (auto it = m.begin(); it!= m.end(); it++)
    {
        max = max > it->second? max : it->second;
    }
    map<int, int> mm;
    for (int i = 0; i < n; i++)
    {
        if (mm.find(a[i]) == mm.end())
        {
            mm[a[i]] = 1;
            if (mm[a[i]] == max)
            {
                cout << a[i] << endl;
                break;
            }
        }
        else
        {
            mm[a[i]]++;
            if (mm[a[i]] == max)
            {
                cout << a[i] << endl;
                break;
            }
        }
    }
    return 0;
}

