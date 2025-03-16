#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int low[n], high[n];
    for (int i = 0; i < n; i++)
    {
        cin >> low[i] >> high[i];
    }
    sort(low, low + n);
    sort(high, high + n);
    if (n % 2)
    {
        cout << high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1 << endl;
    }
    else
    {
        int hh = (high[(n) / 2 - 1] + high[(n) / 2]) / 2;
        int ll = (low[(n) / 2 - 1] + low[(n) / 2]) / 2;
        cout << int((hh - ll) * 2) + 1 << endl;
    }
    return 0;
}
