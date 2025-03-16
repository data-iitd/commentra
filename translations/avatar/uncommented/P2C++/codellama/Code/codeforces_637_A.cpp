#include <iostream>
#include <string>
#include <map>
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
    string a;
    int c = -1, max = 0;
    for (auto i : w)
    {
        if (i.second > max)
        {
            max = i.second;
            a = i.first;
        }
    }
    cout << a << endl;
    return 0;
}