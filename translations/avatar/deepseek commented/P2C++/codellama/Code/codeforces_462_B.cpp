
#include <iostream>
#include <string>
#include <algorithm>
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

    sort(count, count + 26, greater<int>());

    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] >= k)
        {
            res += k * k;
            cout << res << endl;
            return 0;
        }
        k -= count[i];
        res += count[i] * count[i];
    }

    cout << res << endl;

    return 0;
}

