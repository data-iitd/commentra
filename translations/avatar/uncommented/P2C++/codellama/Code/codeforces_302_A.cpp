
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int sa = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '-')
            sa++;
    }
    sa = min(n - sa, sa);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        b -= a;
        if (b % 2 == 0 && b <= sa * 2)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

