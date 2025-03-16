#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, r, curr, s, first, second, ans;
    cin >> l >> r;
    curr = r;
    s = 0;
    while (curr)
    {
        s++;
        first = pow(10, s);
        second = first / 2;
        ans = -1;
        for (int i = l; i <= r; i++)
        {
            if (i >= l and i <= r)
            {
                curr = i;
                string rev = "";
                for (int k = 0; k < curr; k++)
                {
                    rev += to_string(9 - (curr % 10));
                    curr /= 10;
                }
                ans = max(ans, stoi(rev) * curr);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

