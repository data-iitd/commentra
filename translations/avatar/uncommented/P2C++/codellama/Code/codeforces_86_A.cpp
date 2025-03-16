
#include <iostream>
using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;
    int curr = r;
    int s = 0;
    while (curr)
    {
        s++;
        curr /= 10;
    }
    int first = 10 * s;
    int second = first / 2;
    int ans = -1;
    for (int i = l; i <= r; i++)
    {
        if (i >= l && i <= r)
        {
            curr = i;
            string rev = "";
            while (curr)
            {
                rev = (9 - (curr % 10)) + rev;
                curr /= 10;
            }
            ans = max(ans, stoi(rev) * i);
        }
    }
    cout << ans << endl;
    return 0;
}

