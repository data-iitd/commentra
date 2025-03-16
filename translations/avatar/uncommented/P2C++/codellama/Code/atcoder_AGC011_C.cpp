#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int vis[n + 1], ci, cb, cc;
    for (int i = 0; i <= n; i++)
        vis[i] = 0;
    ci = 0;
    cb = 0;
    cc = 0;
    queue<int> q;
    vector<int> g[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (g[i].size() == 0)
                ci++;
            else
            {
                q.push(i);
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    if (vis[u] == 0)
                    {
                        vis[u] = 1;
                        for (int i = 0; i < g[u].size(); i++)
                        {
                            int v = g[u][i];
                            if (vis[v] == 0)
                                q.push(v);
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (g[i].size() == 0)
                ci++;
            else
            {
                if (dfs(i))
                    cb++;
                else
                    cc++;
            }
        }
    }
    cout << ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb;
    return 0;
}

bool dfs(int x)
{
    queue<int> q;
    q.push(x);
    bool flag = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (vis[u] == 0)
        {
            vis[u] = 1;
            for (int i = 0; i < g[u].size(); i++)
            {
                int v = g[u][i];
                if (vis[v] == 0)
                    q.push(v);
            }
        }
        else
            flag &= (vis[u] == 1);
    }
    return flag;
}

