#include <iostream>
using namespace std;
int main()
{
    int N = 368;
    int m[N];
    int f[N];
    int i, a, b, c;
    for (i = 0; i < N; i++)
    {
        m[i] = 0;
        f[i] = 0;
    }
    int n;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        char x;
        int a, b;
        cin >> x >> a >> b;
        b = b + 1;
        if (x == 'M')
        {
            m[a] += 2;
            m[b] -= 2;
        }
        else
        {
            f[a] += 2;
            f[b] -= 2;
        }
    }
    a = 0;
    b = 0;
    c = 0;
    for (i = 0; i < N; i++)
    {
        a += m[i];
        b += f[i];
        if (min(a, b) > c)
        {
            c = min(a, b);
        }
    }
    cout << c;
    return 0;
}



