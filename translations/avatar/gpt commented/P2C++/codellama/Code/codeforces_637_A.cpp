#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<string, int> w;
    for (int i = 0; i < n; i++)
    {
        w[s[i]]++;
    }

    vector<string> v;
    for (auto it = w.begin(); it != w.end(); it++)
    {
        v.push_back(it->first);
    }

    sort(v.begin(), v.end(), [&](string a, string b) {
        return w[a] > w[b];
    });

    int c = -1, a = 0;
    for (int i = 0; i < n; i++)
    {
        if (w[v[i]] == max(w.begin(), w.end(), [](pair<string, int> a, pair<string, int> b) {
            return a.second < b.second;
        })->second)
        {
            if (s.find(v[i]) > c)
            {
                a = v[i];
                c = s.find(v[i]);
            }
        }
    }

    cout << a << endl;

    return 0;
}

