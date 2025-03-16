#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define endl '\n'

// Function to take input as an integer
int inp()
{
    int x;
    cin >> x;
    return x;
}

// Function to take input as a list
vector<int> inpl()
{
    vector<int> v;
    int n = inp();
    for (int i = 0; i < n; i++)
    {
        v.pb(inp());
    }
    return v;
}

// Function to calculate the answer
int solve()
{
    int n, ta, ao;
    cin >> n >> ta >> ao;
    ta--;
    ao--;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a - 1].pb(b - 1);
        g[b - 1].pb(a - 1);
    }

    vector<int> ta_dist(n, -1);
    vector<int> ao_dist(n, -1);

    ta_dist[ta] = 0;
    ao_dist[ao] = 0;

    function<void(int)> ta_dfs = [&](int node) {
        for (int v : g[node])
        {
            if (ta_dist[v] != -1)
                continue;
            ta_dist[v] = ta_dist[node] + 1;
            ta_dfs(v);
        }
    };

    function<void(int)> ao_dfs = [&](int node) {
        for (int v : g[node])
        {
            if (ao_dist[v] != -1)
                continue;
            ao_dist[v] = ao_dist[node] + 1;
            ao_dfs(v);
        }
    };

    ao_dfs(ao);
    ta_dfs(ta);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (ta_dist[i] == -1 || ao_dist[i] == -1 || ta_dist[i] > ao_dist[i])
            continue;
        res = max(res, ao_dist[i]);
    }

    return res - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = inp();
    while (t--)
    {
        cout << solve() << endl;
    }

    return 0;
}

