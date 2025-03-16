
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int sa = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-')
        {
            sa++;
        }
    }
    sa = min(n - sa, sa);
    string ss;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        b -= a;
        if (b % 2 == 1 && b <= sa * 2)
        {
            ss += "1\n";
        }
        else
        {
            ss += "0\n";
        }
    }
    cout << ss;
    return 0;
}

