#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    map<int, int> hp;
    for (int i = 1; i <= n; i++)
        hp[p[i]] = h[i];
    map<int, vector<int>> path;
    for (int i = 1; i <= n; i++)
        path[i] = vector<int>();
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    int c = 0;
    for (auto i : path)
    {
        int f = 0;
        for (auto j : i.second)
            if (hp[i.first] <= hp[j])
            {
                f = 1;
                break;
            }
        if (f == 0)
            c++;
    }
    cout << c << endl;
    return 0;
}



