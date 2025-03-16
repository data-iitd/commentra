
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int count[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] >= k)
        {
            cout << k * k << endl;
            return 0;
        }
        k -= count[i];
    }
    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        res += count[i] * count[i];
    }
    cout << res << endl;
    return 0;
}

