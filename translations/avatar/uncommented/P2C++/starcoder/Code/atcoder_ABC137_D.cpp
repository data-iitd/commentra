#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>> x;
    priority_queue<int> y;
    for (int i = 0; i < n; i++)
    {
        int day, salary;
        cin >> day >> salary;
        x.push(make_pair(-day, -salary));
    }
    while (!x.empty())
    {
        int d, s;
        d = -x.top().first;
        s = -x.top().second;
        x.pop();
        int r = m - y.size();
        if (r >= -d)
        {
            y.push(s);
        }
        else
        {
            y.push(s);
            y.pop();
        }
    }
    cout << -y.top() << endl;
    return 0;
}

