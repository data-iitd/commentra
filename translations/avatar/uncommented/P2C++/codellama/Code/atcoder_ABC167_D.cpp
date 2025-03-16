#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> L;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        L.push_back(x);
    }
    L.insert(L.begin(), -1);
    vector<int> path;
    path.push_back(1);
    int ind = 0;
    int count = 0;
    int x = 1;
    int t = -1;
    bool flag = false;
    map<int, int> Hash;
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
    if (flag == true)
    {
        vector<int> loop;
        for (int i = t; i < path.size(); i++)
        {
            loop.push_back(path[i]);
        }
        if (K < path.size())
        {
            cout << path[K] << endl;
        }
        else
        {
            K = K - path.size();
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