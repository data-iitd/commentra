#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, d, x;
    cin >> N >> d >> x;
    int ret = 0;
    while (N)
    {
        ret += d + (N - 0.5) * x;
        d = d + (d / N) + (5 * x) / (2 * N);
        x += 2 * x / N;
        N--;
    }
    cout << ret << "\n";
    return 0;
}
