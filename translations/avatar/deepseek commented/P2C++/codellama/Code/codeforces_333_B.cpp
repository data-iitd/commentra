
#include <iostream>
using namespace std;

int main()
{
    int n, m, r, c;
    cin >> n >> m;
    int b[2 * n];
    for (int i = 0; i < 2 * n; i++)
        b[i] = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> r >> c;
        b[r - 1] = b[n + c - 1] = 0;
    }
    if (n % 2 && b[n / 2] && b[n + n / 2])
        b[n / 2] = 0;
    int sum = 0;
    for (int i = 0; i < 2 * n; i++)
        sum += b[i];
    cout << sum << endl;
    return 0;
}

