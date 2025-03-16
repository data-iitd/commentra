#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> L(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }
    L.insert(0, -1);
    int x = 1, ind = 0, count = 0, t = -1, flag = false;
    vector<int> path;
    path.push_back(1);
    unordered_map<int, int> Hash;
    for (int i = 0; i < N + 1; i++)
    {
        int ne = L[x];
        if (Hash[ne])
        {
            flag = true;
            t = Hash[ne];
            break;
        }
        path.push_back(ne);
        ind++;
        Hash[ne] = ind;
        x = ne;
    }
    if (flag)
    {
        vector<int> loop = path;
        loop.erase(loop.begin(), loop.begin() + t);
        if (K < (int)path.size())
        {
            cout << path[K] << endl;
        }
        else
        {
            K = K - (int)path.size();
            K = K % loop.size();
            cout << loop[K] << endl;
        }
    }
    else
    {
        cout << path[K - 1] << endl;
    }
    return 0;
}
