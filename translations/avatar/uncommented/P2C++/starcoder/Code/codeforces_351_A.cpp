#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), [](double a, double b) { return a - int(a)!= 0 && b - int(b)!= 0? a < b : a - int(a) < b - int(b); });
    int o = 2 * n - arr.size();
    double arr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr_sum += arr[i];
    }
    double res = 2e9;
    for (int i = 0; i <= n; i++)
    {
        if (i + o >= n)
        {
            res = min(res, abs(i - arr_sum));
        }
    }
    cout << fixed << setprecision(3) << res << endl;
    return 0;
}

