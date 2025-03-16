
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, r[1000], i, ans = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> r[i];
    ans = abs(r[0]);
    for (i = 1; i < n; i++)
        ans += abs(r[i] - r[i - 1]);
    cout << ans << endl;
    return 0;
}

