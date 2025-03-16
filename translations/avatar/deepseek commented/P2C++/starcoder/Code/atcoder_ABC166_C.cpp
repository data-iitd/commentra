#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Step 1: Input the number of nodes (n) and the number of edges (m)
    int n, m;
    cin >> n >> m;

    // Step 2: Create a list of positions (p) from 1 to n
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = i + 1;

    // Step 3: Input the heights (h) of the nodes
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    // Step 4: Create a dictionary (hp) mapping positions to heights
    map<int, int> hp;
    for (int i = 0; i < n; i++)
        hp[p[i]] = h[i];

    // Step 5: Initialize a dictionary (path) to store the adjacency list of the graph
    map<int, vector<int>> path;
    for (int i = 0; i < n; i++)
        path[p[i]] = vector<int>();

    // Step 6: Input the edges of the graph and populate the adjacency list
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    // Step 7: Count the number of nodes that are the highest in their neighborhoods
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        bool f = false;
        for (int j = 0; j < path[p[i]].size(); j++)
        {
            if (hp[p[i]] <= hp[path[p[i]][j]])
            {
                f = true;
                break;
            }
        }
        if (f == false)
            c++;
    }

    // Step 8: Output the count of such nodes
    cout << c << endl;

    return 0;
}

