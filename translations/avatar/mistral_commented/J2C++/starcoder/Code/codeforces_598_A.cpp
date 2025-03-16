
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        long s = 0;
        int x = (int)log2(n);
        x++;
        s = -1 * (long)pow(2, x) + 2 + (long)n * (long)(n + 1) / 2 - (long)pow(2, x);
        cout << s << endl;
    }
    return 0;
}

